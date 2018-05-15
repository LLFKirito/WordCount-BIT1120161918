namespace InterFace
{
    partial class WordCount
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(WordCount));
            this.count = new System.Windows.Forms.Button();
            this.view = new System.Windows.Forms.Button();
            this.txtFilepath = new System.Windows.Forms.TextBox();
            this.txtOutPutInfo = new System.Windows.Forms.TextBox();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.path = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // count
            // 
            this.count.Font = new System.Drawing.Font("幼圆", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.count.Location = new System.Drawing.Point(31, 232);
            this.count.Name = "count";
            this.count.Size = new System.Drawing.Size(752, 27);
            this.count.TabIndex = 0;
            this.count.Text = "统  计";
            this.count.UseVisualStyleBackColor = true;
            this.count.Click += new System.EventHandler(this.count_Click);
            // 
            // view
            // 
            this.view.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.view.Font = new System.Drawing.Font("华文新魏", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.view.Location = new System.Drawing.Point(656, 193);
            this.view.Name = "view";
            this.view.Size = new System.Drawing.Size(127, 27);
            this.view.TabIndex = 1;
            this.view.Text = "浏览";
            this.view.UseVisualStyleBackColor = false;
            this.view.Click += new System.EventHandler(this.view_Click);
            // 
            // txtFilepath
            // 
            this.txtFilepath.Font = new System.Drawing.Font("宋体", 9F);
            this.txtFilepath.Location = new System.Drawing.Point(105, 196);
            this.txtFilepath.Name = "txtFilepath";
            this.txtFilepath.Size = new System.Drawing.Size(522, 21);
            this.txtFilepath.TabIndex = 2;
            // 
            // txtOutPutInfo
            // 
            this.txtOutPutInfo.Font = new System.Drawing.Font("宋体", 9F);
            this.txtOutPutInfo.Location = new System.Drawing.Point(31, 269);
            this.txtOutPutInfo.Multiline = true;
            this.txtOutPutInfo.Name = "txtOutPutInfo";
            this.txtOutPutInfo.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtOutPutInfo.Size = new System.Drawing.Size(752, 161);
            this.txtOutPutInfo.TabIndex = 3;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // path
            // 
            this.path.AutoSize = true;
            this.path.BackColor = System.Drawing.Color.Transparent;
            this.path.Font = new System.Drawing.Font("幼圆", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.path.Location = new System.Drawing.Point(29, 199);
            this.path.Name = "path";
            this.path.Size = new System.Drawing.Size(75, 15);
            this.path.TabIndex = 4;
            this.path.Text = "文件路径";
            this.path.Click += new System.EventHandler(this.path_Click);
            // 
            // WordCount
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::InterFace.Properties.Resources.bg___1;
            this.ClientSize = new System.Drawing.Size(813, 479);
            this.Controls.Add(this.path);
            this.Controls.Add(this.txtOutPutInfo);
            this.Controls.Add(this.txtFilepath);
            this.Controls.Add(this.view);
            this.Controls.Add(this.count);
            this.Font = new System.Drawing.Font("宋体", 10F);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "WordCount";
            this.Text = "WordCount";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button count;
        private System.Windows.Forms.Button view;
        private System.Windows.Forms.TextBox txtFilepath;
        private System.Windows.Forms.TextBox txtOutPutInfo;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Label path;
    }
}

