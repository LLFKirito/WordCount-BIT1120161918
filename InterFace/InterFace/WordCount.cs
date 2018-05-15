using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace InterFace
{
    public partial class WordCount : Form
    {
        public WordCount()
        {
            InitializeComponent();
        }

        public void ProcessOutDataReceived(object sender, DataReceivedEventArgs e)
        {
            if (this.txtOutPutInfo.InvokeRequired)
            {
                this.txtOutPutInfo.Invoke(new Action(() =>
                {
                    this.txtOutPutInfo.AppendText(e.Data + "\r\n");
                }));
            }
            else
            {
                this.txtOutPutInfo.AppendText(e.Data + "\r\n");
            }
        }

        public bool StartProcess(string filename, string[] args)
        {
            try
            {
                string s = "";
                foreach (string arg in args)
                {
                    s = s + arg + " ";
                }
                s = s.Trim();
                Process myprocess = new Process();
                myprocess.OutputDataReceived -= new DataReceivedEventHandler(ProcessOutDataReceived);
                ProcessStartInfo startInfo = new ProcessStartInfo(filename, s);
                startInfo.FileName = "wc.exe";
                startInfo.UseShellExecute = false;
                startInfo.WindowStyle = ProcessWindowStyle.Hidden;
                startInfo.CreateNoWindow = true;
                startInfo.RedirectStandardError = true;
                startInfo.RedirectStandardInput = true;
                startInfo.RedirectStandardOutput = true;
                myprocess.StartInfo = startInfo;
                myprocess.StartInfo.UseShellExecute = false;
                myprocess.Start();

                myprocess.BeginOutputReadLine();
                myprocess.OutputDataReceived += new DataReceivedEventHandler(ProcessOutDataReceived);
                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("启动应用程序时出错！原因：" + ex.Message);
            }
            return false;
        } 

        private void view_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();   //显示选择文件对话框 
            openFileDialog1.InitialDirectory = "c:\\";
            openFileDialog1.Filter = "All files (*.*)|*.*";
            openFileDialog1.FilterIndex = 2;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                this.txtFilepath.Text = openFileDialog1.FileName;     //显示文件路径 
            }
        }

        private void count_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(this.txtFilepath.Text.Trim()))
            {
                MessageBox.Show("请选择文件");
            }
            string[] arg = new string[10];
            arg[0] = "-c"; arg[1] = "-w"; arg[2] = "-l"; arg[3] = "-a";
            arg[4] = this.txtFilepath.Text.Trim();
            StartProcess(@"wc.exe", arg);
        }

        private void path_Click(object sender, EventArgs e)
        {

        }
    }
}