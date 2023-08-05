#pragma once
#include<opencv2/opencv.hpp>
#include"iostream"

namespace MyToolbox {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace cv;
#include"function.h"
	string locdirc = "";
	string savedirc = "";
	string newdirc = "new.jpeg";
	string testdirc = "test.jpeg";
	Mat src, dst,src2;
	std::ostringstream ttext;
	int src_gray, m, radius = 0;
	cv::Point lk;
	std::vector<cv::Vec3f> roi;
	RNG rng(12345);
	vector<vector<cv::Point>> contours;
	vector<Rect> boundRect(contours.size());
	float hist[256] = { 0 };
	Mat hist_img(20, 510, CV_8UC1, Scalar(0));
	Mat hist_img2(20, 510, CV_8UC1, Scalar(0));
	float hist2[256] = { 0 };


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
		
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ down;
	protected:

	protected:

	private: System::Windows::Forms::Panel^ home;
	private: System::Windows::Forms::Panel^ top;
	private: System::Windows::Forms::Button^ close;




	private: System::Windows::Forms::Button^ max;
	private: System::Windows::Forms::Button^ min;



	private: System::Windows::Forms::Panel^ manue;


	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ CandR;
	private: System::Windows::Forms::Button^ Adj;
	private: System::Windows::Forms::Button^ Fil;
	private: System::Windows::Forms::Button^ Blu;
	private: System::Windows::Forms::Panel^ edit;








	private: System::Windows::Forms::Button^ hom;







	private: System::Windows::Forms::Panel^ T;





	private: System::Windows::Forms::Panel^ center;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;








	private: System::Windows::Forms::Panel^ Rotate;

	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel4;
	private: System::Windows::Forms::Button^ rl;
	private: System::Windows::Forms::Button^ rr;

	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Panel^ flip;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel5;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label1;
























private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Panel^ adjust;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel6;
private: System::Windows::Forms::Panel^ tit;
private: System::Windows::Forms::Label^ ti;
private: System::Windows::Forms::Button^ button7;
private: System::Windows::Forms::Panel^ Auto;

private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Button^ adjauto;
private: System::Windows::Forms::Panel^ br;


private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel8;
private: System::Windows::Forms::Label^ bright;
private: System::Windows::Forms::Panel^ con;




private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel9;



private: System::Windows::Forms::TrackBar^ trackBar1;
private: System::Windows::Forms::Label^ label9;

private: System::Windows::Forms::Panel^ ex;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel7;
private: System::Windows::Forms::Label^ label4;

private: System::Windows::Forms::Panel^ hig;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel10;
private: System::Windows::Forms::Label^ label6;

private: System::Windows::Forms::Panel^ s;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel11;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::TrackBar^ trackBar2;
private: System::Windows::Forms::TrackBar^ trackBar3;
private: System::Windows::Forms::TrackBar^ trackBar4;
private: System::Windows::Forms::TrackBar^ trackBar5;

private: System::Windows::Forms::Panel^ clip;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel12;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::TrackBar^ trackBar7;

private: System::Windows::Forms::Label^ label8;






private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::TrackBar^ trackBar10;
private: System::Windows::Forms::Panel^ resize;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel13;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::TrackBar^ trackBar8;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::TrackBar^ trackBar9;
private: System::Windows::Forms::Panel^ zoom;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel14;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::TrackBar^ trackBar11;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::TrackBar^ trackBar6;
private: System::Windows::Forms::Panel^ bw;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel15;
private: System::Windows::Forms::Label^ label19;



private: System::Windows::Forms::Panel^ filters;
private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::Button^ button8;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel16;
private: System::Windows::Forms::Panel^ sh;

private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel17;
private: System::Windows::Forms::Label^ label24;
private: System::Windows::Forms::TrackBar^ trackBar13;
private: System::Windows::Forms::Panel^ sm;

private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel18;
private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::TrackBar^ trackBar14;
private: System::Windows::Forms::Panel^ blr;

private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel19;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::TrackBar^ trackBar15;
private: System::Windows::Forms::Panel^ clr;

private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel20;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::TrackBar^ trackBar16;
private: System::Windows::Forms::Panel^ grain;

private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel21;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::TrackBar^ trackBar17;



private: System::Windows::Forms::Button^ button9;
private: System::Windows::Forms::Button^ dtct;

private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel22;
private: System::Windows::Forms::Button^ button11;
private: System::Windows::Forms::Button^ button12;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel23;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::TrackBar^ trackBar18;
private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::Button^ button13;
private: System::Windows::Forms::Button^ button14;
private: System::Windows::Forms::Panel^ sk;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel24;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::Label^ label31;
private: System::Windows::Forms::TrackBar^ trackBar19;
private: System::Windows::Forms::Label^ label32;








private: System::Windows::Forms::Panel^ befor;


private: System::Windows::Forms::Button^ button15;



private: System::Windows::Forms::Button^ button17;
private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::Label^ sour;
private: System::Windows::Forms::OpenFileDialog^ ofd;
private: System::Windows::Forms::Button^ button18;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Panel^ title;


private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Button^ button19;
private: System::Windows::Forms::PictureBox^ pictureBox3;
private: System::Windows::Forms::Panel^ dbefor;


private: System::Windows::Forms::Panel^ panel4;

private: System::Windows::Forms::Button^ button20;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel26;
private: System::Windows::Forms::Label^ label34;
private: System::Windows::Forms::TextBox^ wa;


private: System::Windows::Forms::Label^ label35;
private: System::Windows::Forms::TextBox^ ha;

private: System::Windows::Forms::Label^ label33;
private: System::Windows::Forms::TextBox^ tpa;

private: System::Windows::Forms::Label^ label36;
private: System::Windows::Forms::TextBox^ Mca;

private: System::Windows::Forms::Label^ label37;
private: System::Windows::Forms::TextBox^ maxca;

private: System::Windows::Forms::Label^ label38;
private: System::Windows::Forms::TextBox^ Aca;

private: System::Windows::Forms::Label^ label39;
private: System::Windows::Forms::TextBox^ ca;

private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Panel^ dafter;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel27;
private: System::Windows::Forms::Panel^ panel6;
private: System::Windows::Forms::Label^ label40;
private: System::Windows::Forms::Button^ button21;
private: System::Windows::Forms::Label^ label41;
private: System::Windows::Forms::TextBox^ wb;


private: System::Windows::Forms::Label^ label42;



private: System::Windows::Forms::TextBox^ hb;
private: System::Windows::Forms::Label^ label43;





private: System::Windows::Forms::TextBox^ tpb;

private: System::Windows::Forms::Label^ label44;
private: System::Windows::Forms::TextBox^ mcb;

private: System::Windows::Forms::Label^ label45;
private: System::Windows::Forms::TextBox^ maxcb;

private: System::Windows::Forms::Label^ label46;
private: System::Windows::Forms::TextBox^ acb;

private: System::Windows::Forms::Label^ label47;
private: System::Windows::Forms::TextBox^ cb;

private: System::Windows::Forms::Button^ button22;
private: System::Windows::Forms::Label^ label49;
private: System::Windows::Forms::TextBox^ db;

private: System::Windows::Forms::Label^ label48;
private: System::Windows::Forms::TextBox^ da;
private: System::Windows::Forms::TextBox^ infoa;

private: System::Windows::Forms::TextBox^ infob;
private: System::Windows::Forms::Button^ button23;
private: System::Windows::Forms::Button^ button25;
private: System::Windows::Forms::Button^ button24;
private: System::Windows::Forms::TrackBar^ trackBar12;
private: System::Windows::Forms::TrackBar^ trackBar20;
private: System::Windows::Forms::Label^ label50;
private: System::Windows::Forms::Label^ label51;
private: System::Windows::Forms::Label^ label52;
private: System::Windows::Forms::Button^ button26;
private: System::Windows::Forms::Panel^ Effect;
private: System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::Label^ label53;
private: System::Windows::Forms::Button^ button27;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel28;
private: System::Windows::Forms::Panel^ panel7;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel29;


private: System::Windows::Forms::Panel^ panel8;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel30;
private: System::Windows::Forms::Label^ label55;
private: System::Windows::Forms::Label^ label56;
private: System::Windows::Forms::TrackBar^ trackBar22;
private: System::Windows::Forms::Label^ label57;
private: System::Windows::Forms::TrackBar^ trackBar23;


private: System::Windows::Forms::Panel^ panel9;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel31;

private: System::Windows::Forms::TrackBar^ trackBar25;
private: System::Windows::Forms::Panel^ panel10;










private: System::Windows::Forms::Button^ button31;
private: System::Windows::Forms::Button^ button28;
private: System::Windows::Forms::Panel^ detect;
private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Label^ label54;
private: System::Windows::Forms::Button^ button29;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel32;
private: System::Windows::Forms::Panel^ panel11;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel33;
private: System::Windows::Forms::Button^ button30;
private: System::Windows::Forms::Panel^ panel12;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel34;
private: System::Windows::Forms::Label^ label58;
private: System::Windows::Forms::Label^ label59;


private: System::Windows::Forms::TrackBar^ trackBar24;




private: System::Windows::Forms::Panel^ panel14;


private: System::Windows::Forms::Panel^ liquify;
private: System::Windows::Forms::Panel^ panel13;
private: System::Windows::Forms::Label^ label62;
private: System::Windows::Forms::Button^ button10;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel35;
private: System::Windows::Forms::Panel^ panel15;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel36;



private: System::Windows::Forms::Panel^ panel16;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel37;
private: System::Windows::Forms::Label^ label64;

private: System::Windows::Forms::TrackBar^ trackBar26;


private: System::Windows::Forms::Panel^ panel17;
private: System::Windows::Forms::Label^ label63;
private: System::Windows::Forms::TrackBar^ trackBar28;
private: System::Windows::Forms::Panel^ Histogram;

private: System::Windows::Forms::Panel^ panel18;

private: System::Windows::Forms::Label^ label65;
private: System::Windows::Forms::Button^ button33;
private: System::Windows::Forms::PictureBox^ pictureBox4;
private: System::Windows::Forms::Label^ label66;
private: System::Windows::Forms::TextBox^ histogramtextBox;
private: System::Windows::Forms::Button^ button32;
private: System::Windows::Forms::Button^ button34;
private: System::Windows::Forms::Button^ button35;
private: System::Windows::Forms::Button^ button36;
private: System::Windows::Forms::Label^ label60;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::TrackBar^ trackBar27;
private: System::Windows::Forms::TrackBar^ trackBar21;
private: System::Windows::Forms::Label^ label67;
private: System::Windows::Forms::Label^ label61;
private: System::Windows::Forms::Label^ label69;
private: System::Windows::Forms::Label^ label68;
private: System::Windows::Forms::Button^ done;
private: System::Windows::Forms::TrackBar^ trackBar29;






































































	protected:
	protected:
	protected:
	private: System::ComponentModel::IContainer^ components;
	protected:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::ToolTip^ toolTip1;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::ToolTip^ toolTip2;
			this->rl = (gcnew System::Windows::Forms::Button());
			this->rr = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->trackBar6 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar11 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar7 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar10 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar8 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar9 = (gcnew System::Windows::Forms::TrackBar());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->trackBar24 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar19 = (gcnew System::Windows::Forms::TrackBar());
			this->down = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel22 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel23 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->trackBar18 = (gcnew System::Windows::Forms::TrackBar());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->home = (gcnew System::Windows::Forms::Panel());
			this->dafter = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel26 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->wa = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->ha = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->tpa = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->Mca = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->maxca = (gcnew System::Windows::Forms::TextBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->Aca = (gcnew System::Windows::Forms::TextBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->ca = (gcnew System::Windows::Forms::TextBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->da = (gcnew System::Windows::Forms::TextBox());
			this->dbefor = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel27 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->wb = (gcnew System::Windows::Forms::TextBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->hb = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->tpb = (gcnew System::Windows::Forms::TextBox());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->mcb = (gcnew System::Windows::Forms::TextBox());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->maxcb = (gcnew System::Windows::Forms::TextBox());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->acb = (gcnew System::Windows::Forms::TextBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->cb = (gcnew System::Windows::Forms::TextBox());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->db = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->infoa = (gcnew System::Windows::Forms::TextBox());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->befor = (gcnew System::Windows::Forms::Panel());
			this->infob = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->title = (gcnew System::Windows::Forms::Panel());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->Histogram = (gcnew System::Windows::Forms::Panel());
			this->histogramtextBox = (gcnew System::Windows::Forms::TextBox());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->sour = (gcnew System::Windows::Forms::Label());
			this->edit = (gcnew System::Windows::Forms::Panel());
			this->T = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->sk = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel24 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->Rotate = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->zoom = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel14 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->clip = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel12 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->resize = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel13 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->flip = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel5 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->done = (gcnew System::Windows::Forms::Button());
			this->top = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->max = (gcnew System::Windows::Forms::Button());
			this->close = (gcnew System::Windows::Forms::Button());
			this->min = (gcnew System::Windows::Forms::Button());
			this->manue = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->hom = (gcnew System::Windows::Forms::Button());
			this->CandR = (gcnew System::Windows::Forms::Button());
			this->Adj = (gcnew System::Windows::Forms::Button());
			this->Fil = (gcnew System::Windows::Forms::Button());
			this->Blu = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->dtct = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->center = (gcnew System::Windows::Forms::Panel());
			this->detect = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel32 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel33 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel34 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->adjust = (gcnew System::Windows::Forms::Panel());
			this->tit = (gcnew System::Windows::Forms::Panel());
			this->ti = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel6 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->Auto = (gcnew System::Windows::Forms::Panel());
			this->adjauto = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->br = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel8 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->bright = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->con = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel9 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->hig = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel10 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->ex = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel7 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->s = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel11 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->bw = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel15 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->trackBar29 = (gcnew System::Windows::Forms::TrackBar());
			this->liquify = (gcnew System::Windows::Forms::Panel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel35 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel36 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->trackBar28 = (gcnew System::Windows::Forms::TrackBar());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel37 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->trackBar26 = (gcnew System::Windows::Forms::TrackBar());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->filters = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel16 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->sm = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel18 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->trackBar14 = (gcnew System::Windows::Forms::TrackBar());
			this->sh = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel17 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->trackBar27 = (gcnew System::Windows::Forms::TrackBar());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->trackBar13 = (gcnew System::Windows::Forms::TrackBar());
			this->grain = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel21 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->trackBar17 = (gcnew System::Windows::Forms::TrackBar());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->trackBar12 = (gcnew System::Windows::Forms::TrackBar());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->trackBar20 = (gcnew System::Windows::Forms::TrackBar());
			this->clr = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel20 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->trackBar16 = (gcnew System::Windows::Forms::TrackBar());
			this->blr = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel19 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->trackBar21 = (gcnew System::Windows::Forms::TrackBar());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->trackBar15 = (gcnew System::Windows::Forms::TrackBar());
			this->Effect = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel28 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel29 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel30 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->trackBar22 = (gcnew System::Windows::Forms::TrackBar());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->trackBar23 = (gcnew System::Windows::Forms::TrackBar());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel31 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->trackBar25 = (gcnew System::Windows::Forms::TrackBar());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->ofd = (gcnew System::Windows::Forms::OpenFileDialog());
			toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar19))->BeginInit();
			this->down->SuspendLayout();
			this->flowLayoutPanel22->SuspendLayout();
			this->flowLayoutPanel23->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar18))->BeginInit();
			this->home->SuspendLayout();
			this->dafter->SuspendLayout();
			this->flowLayoutPanel26->SuspendLayout();
			this->panel4->SuspendLayout();
			this->dbefor->SuspendLayout();
			this->flowLayoutPanel27->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->befor->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->title->SuspendLayout();
			this->Histogram->SuspendLayout();
			this->panel18->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->edit->SuspendLayout();
			this->T->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->sk->SuspendLayout();
			this->flowLayoutPanel24->SuspendLayout();
			this->Rotate->SuspendLayout();
			this->flowLayoutPanel4->SuspendLayout();
			this->zoom->SuspendLayout();
			this->flowLayoutPanel14->SuspendLayout();
			this->clip->SuspendLayout();
			this->flowLayoutPanel12->SuspendLayout();
			this->resize->SuspendLayout();
			this->flowLayoutPanel13->SuspendLayout();
			this->flip->SuspendLayout();
			this->flowLayoutPanel5->SuspendLayout();
			this->top->SuspendLayout();
			this->manue->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->center->SuspendLayout();
			this->detect->SuspendLayout();
			this->panel2->SuspendLayout();
			this->flowLayoutPanel32->SuspendLayout();
			this->panel11->SuspendLayout();
			this->flowLayoutPanel33->SuspendLayout();
			this->panel12->SuspendLayout();
			this->flowLayoutPanel34->SuspendLayout();
			this->adjust->SuspendLayout();
			this->tit->SuspendLayout();
			this->flowLayoutPanel6->SuspendLayout();
			this->Auto->SuspendLayout();
			this->br->SuspendLayout();
			this->flowLayoutPanel8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->con->SuspendLayout();
			this->flowLayoutPanel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->hig->SuspendLayout();
			this->flowLayoutPanel10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			this->ex->SuspendLayout();
			this->flowLayoutPanel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->s->SuspendLayout();
			this->flowLayoutPanel11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->BeginInit();
			this->bw->SuspendLayout();
			this->flowLayoutPanel15->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar29))->BeginInit();
			this->liquify->SuspendLayout();
			this->panel13->SuspendLayout();
			this->flowLayoutPanel35->SuspendLayout();
			this->panel15->SuspendLayout();
			this->flowLayoutPanel36->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar28))->BeginInit();
			this->panel16->SuspendLayout();
			this->flowLayoutPanel37->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar26))->BeginInit();
			this->filters->SuspendLayout();
			this->panel5->SuspendLayout();
			this->flowLayoutPanel16->SuspendLayout();
			this->sm->SuspendLayout();
			this->flowLayoutPanel18->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar14))->BeginInit();
			this->sh->SuspendLayout();
			this->flowLayoutPanel17->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar13))->BeginInit();
			this->grain->SuspendLayout();
			this->flowLayoutPanel21->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar20))->BeginInit();
			this->clr->SuspendLayout();
			this->flowLayoutPanel20->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar16))->BeginInit();
			this->blr->SuspendLayout();
			this->flowLayoutPanel19->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar15))->BeginInit();
			this->Effect->SuspendLayout();
			this->panel3->SuspendLayout();
			this->flowLayoutPanel28->SuspendLayout();
			this->panel7->SuspendLayout();
			this->flowLayoutPanel29->SuspendLayout();
			this->panel8->SuspendLayout();
			this->flowLayoutPanel30->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar23))->BeginInit();
			this->panel9->SuspendLayout();
			this->flowLayoutPanel31->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar25))->BeginInit();
			this->SuspendLayout();
			// 
			// toolTip1
			// 
			toolTip1->AutomaticDelay = 50;
			toolTip1->AutoPopDelay = 50000;
			toolTip1->BackColor = System::Drawing::SystemColors::WindowFrame;
			toolTip1->ForeColor = System::Drawing::Color::LightGray;
			toolTip1->InitialDelay = 50;
			toolTip1->IsBalloon = true;
			toolTip1->ReshowDelay = 10;
			toolTip1->ShowAlways = true;
			toolTip1->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			toolTip1->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &MyForm::toolTip1_Popup);
			// 
			// rl
			// 
			this->rl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"rl.BackgroundImage")));
			this->rl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->rl->Cursor = System::Windows::Forms::Cursors::Hand;
			this->rl->FlatAppearance->BorderSize = 0;
			this->rl->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->rl->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->rl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rl->Location = System::Drawing::Point(3, 47);
			this->rl->Name = L"rl";
			this->rl->Size = System::Drawing::Size(134, 44);
			this->rl->TabIndex = 6;
			toolTip1->SetToolTip(this->rl, L"ROTATE LEFT");
			this->rl->UseVisualStyleBackColor = true;
			this->rl->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// rr
			// 
			this->rr->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"rr.BackgroundImage")));
			this->rr->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->rr->Cursor = System::Windows::Forms::Cursors::Hand;
			this->rr->FlatAppearance->BorderSize = 0;
			this->rr->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->rr->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->rr->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rr->Location = System::Drawing::Point(143, 47);
			this->rr->Name = L"rr";
			this->rr->Size = System::Drawing::Size(134, 44);
			this->rr->TabIndex = 9;
			toolTip1->SetToolTip(this->rr, L"ROTATE RIGHT");
			this->rr->UseVisualStyleBackColor = true;
			this->rr->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			// 
			// button4
			// 
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->Location = System::Drawing::Point(135, 47);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(134, 49);
			this->button4->TabIndex = 6;
			toolTip1->SetToolTip(this->button4, L"FLIP VERTICAL");
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			// 
			// button5
			// 
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->Location = System::Drawing::Point(3, 47);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(126, 49);
			this->button5->TabIndex = 9;
			toolTip1->SetToolTip(this->button5, L"FLIP HORIZONTAL");
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click_1);
			// 
			// button32
			// 
			this->button32->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button32.BackgroundImage")));
			this->button32->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button32->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button32->FlatAppearance->BorderSize = 0;
			this->button32->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button32->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button32->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button32->Location = System::Drawing::Point(3, 95);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(126, 44);
			this->button32->TabIndex = 23;
			toolTip1->SetToolTip(this->button32, L"                             -->Contour Vertical<--\r\n!--Contour image matches the"
				L" shape of the selected filter--!\r\n");
			this->button32->UseVisualStyleBackColor = true;
			this->button32->Click += gcnew System::EventHandler(this, &MyForm::button32_Click_2);
			// 
			// button34
			// 
			this->button34->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button34.BackgroundImage")));
			this->button34->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button34->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button34->FlatAppearance->BorderSize = 0;
			this->button34->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button34->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button34->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button34->Location = System::Drawing::Point(3, 145);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(126, 44);
			this->button34->TabIndex = 24;
			toolTip1->SetToolTip(this->button34, L"                           -->Contour Horizontal<--\r\n!--Contour image matches the"
				L" shape of the selected filter--!\r\n");
			this->button34->UseVisualStyleBackColor = true;
			this->button34->Click += gcnew System::EventHandler(this, &MyForm::button34_Click);
			// 
			// button35
			// 
			this->button35->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button35.BackgroundImage")));
			this->button35->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button35->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button35->FlatAppearance->BorderSize = 0;
			this->button35->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button35->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button35->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button35->Location = System::Drawing::Point(135, 95);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(126, 44);
			this->button35->TabIndex = 25;
			toolTip1->SetToolTip(this->button35, L"                          -->Contour Diagonal<--\r\n!--Contour image matches the sh"
				L"ape of the selected filter--!\r\n");
			this->button35->UseVisualStyleBackColor = true;
			this->button35->Click += gcnew System::EventHandler(this, &MyForm::button35_Click);
			// 
			// button36
			// 
			this->button36->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button36.BackgroundImage")));
			this->button36->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button36->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button36->FlatAppearance->BorderSize = 0;
			this->button36->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button36->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button36->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button36->Location = System::Drawing::Point(135, 145);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(126, 44);
			this->button36->TabIndex = 26;
			toolTip1->SetToolTip(this->button36, L"                           -->Contour all<--\r\n!--Contour image matches the shape "
				L"of the selected filter--!\r\n");
			this->button36->UseVisualStyleBackColor = true;
			this->button36->Click += gcnew System::EventHandler(this, &MyForm::button36_Click);
			// 
			// trackBar6
			// 
			this->trackBar6->AutoSize = false;
			this->trackBar6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar6->Location = System::Drawing::Point(51, 97);
			this->trackBar6->Maximum = 360;
			this->trackBar6->Name = L"trackBar6";
			this->trackBar6->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->trackBar6->Size = System::Drawing::Size(180, 30);
			this->trackBar6->TabIndex = 21;
			this->trackBar6->TickStyle = System::Windows::Forms::TickStyle::Both;
			toolTip1->SetToolTip(this->trackBar6, L"-->PLEASE CLICK DONE <--\r\n -->TO SAVE THIS EDIT<--\r\n\r\n\r\n");
			toolTip2->SetToolTip(this->trackBar6, L"-->PLEASE CLICK DONE <--\r\n -->TO SAVE THIS EDIT<--\r\n\r\n");
			this->trackBar6->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar6_Scroll);
			// 
			// trackBar11
			// 
			this->trackBar11->AutoSize = false;
			this->trackBar11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar11->Location = System::Drawing::Point(58, 47);
			this->trackBar11->Maximum = 500;
			this->trackBar11->Minimum = 100;
			this->trackBar11->Name = L"trackBar11";
			this->trackBar11->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->trackBar11->Size = System::Drawing::Size(180, 30);
			this->trackBar11->TabIndex = 17;
			this->trackBar11->TickStyle = System::Windows::Forms::TickStyle::Both;
			toolTip1->SetToolTip(this->trackBar11, L"-->PLEASE CLICK DONE <--\r\n -->TO SAVE THIS EDIT<--\r\n\r\n\r\n");
			this->trackBar11->Value = 100;
			this->trackBar11->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar11_Scroll);
			// 
			// trackBar7
			// 
			this->trackBar7->AutoSize = false;
			this->trackBar7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar7->Location = System::Drawing::Point(76, 47);
			this->trackBar7->Maximum = 100;
			this->trackBar7->Minimum = -100;
			this->trackBar7->Name = L"trackBar7";
			this->trackBar7->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->trackBar7->Size = System::Drawing::Size(180, 30);
			this->trackBar7->TabIndex = 17;
			this->trackBar7->TickStyle = System::Windows::Forms::TickStyle::Both;
			toolTip1->SetToolTip(this->trackBar7, L"-->PLEASE CLICK DONE <--\r\n -->TO SAVE THIS EDIT<--\r\n\r\n\r\n");
			this->trackBar7->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar7_Scroll);
			// 
			// trackBar10
			// 
			this->trackBar10->AutoSize = false;
			this->trackBar10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar10->Location = System::Drawing::Point(76, 91);
			this->trackBar10->Maximum = 100;
			this->trackBar10->Minimum = -100;
			this->trackBar10->Name = L"trackBar10";
			this->trackBar10->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->trackBar10->Size = System::Drawing::Size(180, 30);
			this->trackBar10->TabIndex = 21;
			this->trackBar10->TickStyle = System::Windows::Forms::TickStyle::Both;
			toolTip1->SetToolTip(this->trackBar10, L"-->PLEASE CLICK DONE <--\r\n -->TO SAVE THIS EDIT<--\r\n\r\n\r\n");
			this->trackBar10->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar10_Scroll);
			// 
			// trackBar8
			// 
			this->trackBar8->AutoSize = false;
			this->trackBar8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar8->Location = System::Drawing::Point(76, 47);
			this->trackBar8->Maximum = 200;
			this->trackBar8->Minimum = 1;
			this->trackBar8->Name = L"trackBar8";
			this->trackBar8->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->trackBar8->Size = System::Drawing::Size(180, 30);
			this->trackBar8->TabIndex = 17;
			this->trackBar8->TickStyle = System::Windows::Forms::TickStyle::Both;
			toolTip1->SetToolTip(this->trackBar8, L"-->PLEASE CLICK DONE <--\r\n -->TO SAVE THIS EDIT<--\r\n\r\n\r\n");
			this->trackBar8->Value = 100;
			this->trackBar8->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar8_Scroll);
			// 
			// trackBar9
			// 
			this->trackBar9->AutoSize = false;
			this->trackBar9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar9->Location = System::Drawing::Point(76, 91);
			this->trackBar9->Maximum = 200;
			this->trackBar9->Minimum = 1;
			this->trackBar9->Name = L"trackBar9";
			this->trackBar9->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->trackBar9->Size = System::Drawing::Size(180, 30);
			this->trackBar9->TabIndex = 21;
			this->trackBar9->TickStyle = System::Windows::Forms::TickStyle::Both;
			toolTip1->SetToolTip(this->trackBar9, L"-->PLEASE CLICK DONE <--\r\n -->TO SAVE THIS EDIT<--\r\n\r\n\r\n");
			this->trackBar9->Value = 100;
			this->trackBar9->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar9_Scroll);
			// 
			// button23
			// 
			this->button23->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button23->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button23.BackgroundImage")));
			this->button23->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button23->FlatAppearance->BorderSize = 0;
			this->button23->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button23->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->button23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button23->Location = System::Drawing::Point(3, 135);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(83, 53);
			this->button23->TabIndex = 18;
			toolTip1->SetToolTip(this->button23, L"Blur the detail in the image to match the shape of the selected filter");
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// button25
			// 
			this->button25->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button25->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button25.BackgroundImage")));
			this->button25->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button25->FlatAppearance->BorderSize = 0;
			this->button25->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button25->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->button25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button25->Location = System::Drawing::Point(92, 135);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(83, 53);
			this->button25->TabIndex = 20;
			toolTip1->SetToolTip(this->button25, L"Blur the detail in the image to match the shape of the selected filter");
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
			// 
			// button24
			// 
			this->button24->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button24->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button24.BackgroundImage")));
			this->button24->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button24->FlatAppearance->BorderSize = 0;
			this->button24->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button24->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->button24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button24->Location = System::Drawing::Point(181, 135);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(83, 53);
			this->button24->TabIndex = 19;
			toolTip1->SetToolTip(this->button24, L"Blur the detail in the image to match the shape of the selected filter");
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
			// 
			// trackBar24
			// 
			this->trackBar24->AutoSize = false;
			this->trackBar24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar24->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar24->Location = System::Drawing::Point(51, 51);
			this->trackBar24->Maximum = 255;
			this->trackBar24->Name = L"trackBar24";
			this->trackBar24->Size = System::Drawing::Size(234, 25);
			this->trackBar24->TabIndex = 18;
			this->trackBar24->TickStyle = System::Windows::Forms::TickStyle::Both;
			toolTip1->SetToolTip(this->trackBar24, L"\r\n");
			this->trackBar24->Value = 1;
			this->trackBar24->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar24_Scroll);
			// 
			// toolTip2
			// 
			toolTip2->AutomaticDelay = 50;
			toolTip2->AutoPopDelay = 50000;
			toolTip2->BackColor = System::Drawing::SystemColors::WindowFrame;
			toolTip2->ForeColor = System::Drawing::Color::LightGray;
			toolTip2->InitialDelay = 50;
			toolTip2->IsBalloon = true;
			toolTip2->ReshowDelay = 10;
			toolTip2->ShowAlways = true;
			toolTip2->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
			// 
			// trackBar19
			// 
			this->trackBar19->AutoSize = false;
			this->trackBar19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar19->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar19->Location = System::Drawing::Point(58, 47);
			this->trackBar19->Maximum = 100;
			this->trackBar19->Minimum = -100;
			this->trackBar19->Name = L"trackBar19";
			this->trackBar19->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->trackBar19->Size = System::Drawing::Size(180, 30);
			this->trackBar19->TabIndex = 17;
			this->trackBar19->TickStyle = System::Windows::Forms::TickStyle::Both;
			toolTip2->SetToolTip(this->trackBar19, L"-->PLEASE CLICK DONE <--\r\n -->TO SAVE THIS EDIT<--\r\n\r\n\r\n");
			this->trackBar19->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar19_Scroll);
			// 
			// down
			// 
			this->down->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->down->Controls->Add(this->flowLayoutPanel22);
			this->down->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->down->Location = System::Drawing::Point(185, 699);
			this->down->Name = L"down";
			this->down->Size = System::Drawing::Size(1263, 72);
			this->down->TabIndex = 2;
			this->down->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::down_Paint);
			// 
			// flowLayoutPanel22
			// 
			this->flowLayoutPanel22->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->flowLayoutPanel22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel22->Controls->Add(this->button11);
			this->flowLayoutPanel22->Controls->Add(this->button12);
			this->flowLayoutPanel22->Controls->Add(this->flowLayoutPanel23);
			this->flowLayoutPanel22->Controls->Add(this->button13);
			this->flowLayoutPanel22->Controls->Add(this->button14);
			this->flowLayoutPanel22->Location = System::Drawing::Point(324, 8);
			this->flowLayoutPanel22->Name = L"flowLayoutPanel22";
			this->flowLayoutPanel22->Size = System::Drawing::Size(847, 64);
			this->flowLayoutPanel22->TabIndex = 7;
			// 
			// button11
			// 
			this->button11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button11->FlatAppearance->BorderColor = System::Drawing::SystemColors::MenuHighlight;
			this->button11->FlatAppearance->BorderSize = 2;
			this->button11->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button11->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::Color::Gainsboro;
			this->button11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button11.Image")));
			this->button11->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button11->Location = System::Drawing::Point(3, 3);
			this->button11->Name = L"button11";
			this->button11->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button11->Size = System::Drawing::Size(145, 54);
			this->button11->TabIndex = 5;
			this->button11->Text = L"Compare";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button12->FlatAppearance->BorderColor = System::Drawing::SystemColors::MenuHighlight;
			this->button12->FlatAppearance->BorderSize = 2;
			this->button12->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::Color::Gainsboro;
			this->button12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button12.Image")));
			this->button12->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button12->Location = System::Drawing::Point(154, 3);
			this->button12->Name = L"button12";
			this->button12->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button12->Size = System::Drawing::Size(128, 54);
			this->button12->TabIndex = 6;
			this->button12->Text = L"Reset";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// flowLayoutPanel23
			// 
			this->flowLayoutPanel23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel23->Controls->Add(this->label29);
			this->flowLayoutPanel23->Controls->Add(this->trackBar18);
			this->flowLayoutPanel23->Controls->Add(this->label30);
			this->flowLayoutPanel23->Location = System::Drawing::Point(288, 3);
			this->flowLayoutPanel23->Name = L"flowLayoutPanel23";
			this->flowLayoutPanel23->Size = System::Drawing::Size(299, 60);
			this->flowLayoutPanel23->TabIndex = 8;
			this->flowLayoutPanel23->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel23_Paint);
			// 
			// label29
			// 
			this->label29->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->ForeColor = System::Drawing::Color::Gainsboro;
			this->label29->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label29.Image")));
			this->label29->Location = System::Drawing::Point(3, 0);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(49, 44);
			this->label29->TabIndex = 20;
			this->label29->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar18
			// 
			this->trackBar18->AutoSize = false;
			this->trackBar18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar18->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar18->Location = System::Drawing::Point(58, 3);
			this->trackBar18->Maximum = 500;
			this->trackBar18->Minimum = 100;
			this->trackBar18->Name = L"trackBar18";
			this->trackBar18->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->trackBar18->Size = System::Drawing::Size(174, 31);
			this->trackBar18->TabIndex = 17;
			this->trackBar18->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar18->Value = 100;
			this->trackBar18->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar18_Scroll);
			// 
			// label30
			// 
			this->label30->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->ForeColor = System::Drawing::Color::Gainsboro;
			this->label30->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label30.Image")));
			this->label30->Location = System::Drawing::Point(238, 0);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(29, 44);
			this->label30->TabIndex = 19;
			this->label30->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button13
			// 
			this->button13->FlatAppearance->BorderColor = System::Drawing::SystemColors::MenuHighlight;
			this->button13->FlatAppearance->BorderSize = 2;
			this->button13->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button13->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->ForeColor = System::Drawing::Color::Gainsboro;
			this->button13->Location = System::Drawing::Point(593, 3);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(119, 54);
			this->button13->TabIndex = 8;
			this->button13->Text = L"Save";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->FlatAppearance->BorderColor = System::Drawing::SystemColors::MenuHighlight;
			this->button14->FlatAppearance->BorderSize = 2;
			this->button14->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button14->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->ForeColor = System::Drawing::Color::Gainsboro;
			this->button14->Location = System::Drawing::Point(718, 3);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(119, 54);
			this->button14->TabIndex = 9;
			this->button14->Text = L"Close";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// home
			// 
			this->home->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->home->Controls->Add(this->Histogram);
			this->home->Controls->Add(this->dbefor);
			this->home->Controls->Add(this->dafter);
			this->home->Controls->Add(this->pictureBox3);
			this->home->Controls->Add(this->button17);
			this->home->Controls->Add(this->infoa);
			this->home->Controls->Add(this->pictureBox2);
			this->home->Controls->Add(this->befor);
			this->home->Dock = System::Windows::Forms::DockStyle::Fill;
			this->home->Location = System::Drawing::Point(0, 0);
			this->home->Name = L"home";
			this->home->Size = System::Drawing::Size(1263, 660);
			this->home->TabIndex = 3;
			this->home->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel4_Paint);
			// 
			// dafter
			// 
			this->dafter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->dafter->Controls->Add(this->flowLayoutPanel26);
			this->dafter->Location = System::Drawing::Point(535, 83);
			this->dafter->Name = L"dafter";
			this->dafter->Size = System::Drawing::Size(344, 352);
			this->dafter->TabIndex = 8;
			this->dafter->Visible = false;
			// 
			// flowLayoutPanel26
			// 
			this->flowLayoutPanel26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel26->Controls->Add(this->panel4);
			this->flowLayoutPanel26->Controls->Add(this->label34);
			this->flowLayoutPanel26->Controls->Add(this->wa);
			this->flowLayoutPanel26->Controls->Add(this->label35);
			this->flowLayoutPanel26->Controls->Add(this->ha);
			this->flowLayoutPanel26->Controls->Add(this->label33);
			this->flowLayoutPanel26->Controls->Add(this->tpa);
			this->flowLayoutPanel26->Controls->Add(this->label36);
			this->flowLayoutPanel26->Controls->Add(this->Mca);
			this->flowLayoutPanel26->Controls->Add(this->label37);
			this->flowLayoutPanel26->Controls->Add(this->maxca);
			this->flowLayoutPanel26->Controls->Add(this->label38);
			this->flowLayoutPanel26->Controls->Add(this->Aca);
			this->flowLayoutPanel26->Controls->Add(this->label39);
			this->flowLayoutPanel26->Controls->Add(this->ca);
			this->flowLayoutPanel26->Controls->Add(this->label48);
			this->flowLayoutPanel26->Controls->Add(this->da);
			this->flowLayoutPanel26->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel26->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel26->Name = L"flowLayoutPanel26";
			this->flowLayoutPanel26->Size = System::Drawing::Size(344, 352);
			this->flowLayoutPanel26->TabIndex = 9;
			this->flowLayoutPanel26->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel26_Paint_2);
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->panel4->Controls->Add(this->label21);
			this->panel4->Controls->Add(this->button20);
			this->panel4->Location = System::Drawing::Point(3, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Padding = System::Windows::Forms::Padding(10, 12, 10, 10);
			this->panel4->Size = System::Drawing::Size(341, 47);
			this->panel4->TabIndex = 7;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel4_Paint_1);
			// 
			// label21
			// 
			this->label21->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::Color::Gainsboro;
			this->label21->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label21.Image")));
			this->label21->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label21->Location = System::Drawing::Point(52, 1);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(211, 44);
			this->label21->TabIndex = 15;
			this->label21->Text = L"Details";
			this->label21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button20
			// 
			this->button20->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button20->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button20.BackgroundImage")));
			this->button20->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button20->FlatAppearance->BorderSize = 0;
			this->button20->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button20->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button20->Location = System::Drawing::Point(282, 6);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(20, 30);
			this->button20->TabIndex = 8;
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// label34
			// 
			this->label34->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->ForeColor = System::Drawing::Color::Gainsboro;
			this->label34->Location = System::Drawing::Point(3, 53);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(201, 37);
			this->label34->TabIndex = 15;
			this->label34->Text = L"Width";
			this->label34->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label34->Click += gcnew System::EventHandler(this, &MyForm::label34_Click);
			// 
			// wa
			// 
			this->wa->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->wa->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->wa->Cursor = System::Windows::Forms::Cursors::Default;
			this->wa->Dock = System::Windows::Forms::DockStyle::Top;
			this->wa->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wa->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->wa->Location = System::Drawing::Point(210, 56);
			this->wa->Multiline = true;
			this->wa->Name = L"wa";
			this->wa->ReadOnly = true;
			this->wa->Size = System::Drawing::Size(102, 31);
			this->wa->TabIndex = 11;
			this->wa->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->wa->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged_1);
			// 
			// label35
			// 
			this->label35->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label35->ForeColor = System::Drawing::Color::Gainsboro;
			this->label35->Location = System::Drawing::Point(3, 90);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(201, 37);
			this->label35->TabIndex = 16;
			this->label35->Text = L"Hight";
			this->label35->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label35->Click += gcnew System::EventHandler(this, &MyForm::label35_Click);
			// 
			// ha
			// 
			this->ha->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->ha->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ha->Cursor = System::Windows::Forms::Cursors::Default;
			this->ha->Dock = System::Windows::Forms::DockStyle::Top;
			this->ha->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ha->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->ha->Location = System::Drawing::Point(210, 93);
			this->ha->Multiline = true;
			this->ha->Name = L"ha";
			this->ha->ReadOnly = true;
			this->ha->Size = System::Drawing::Size(102, 31);
			this->ha->TabIndex = 12;
			this->ha->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->ha->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label33
			// 
			this->label33->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label33->ForeColor = System::Drawing::Color::Gainsboro;
			this->label33->Location = System::Drawing::Point(3, 127);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(201, 37);
			this->label33->TabIndex = 18;
			this->label33->Text = L"Total Px";
			this->label33->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tpa
			// 
			this->tpa->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->tpa->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tpa->Cursor = System::Windows::Forms::Cursors::Default;
			this->tpa->Dock = System::Windows::Forms::DockStyle::Top;
			this->tpa->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tpa->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->tpa->Location = System::Drawing::Point(210, 130);
			this->tpa->Multiline = true;
			this->tpa->Name = L"tpa";
			this->tpa->ReadOnly = true;
			this->tpa->Size = System::Drawing::Size(102, 31);
			this->tpa->TabIndex = 17;
			this->tpa->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label36
			// 
			this->label36->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label36->ForeColor = System::Drawing::Color::Gainsboro;
			this->label36->Location = System::Drawing::Point(3, 164);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(201, 37);
			this->label36->TabIndex = 20;
			this->label36->Text = L"Min Color";
			this->label36->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Mca
			// 
			this->Mca->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->Mca->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Mca->Cursor = System::Windows::Forms::Cursors::Default;
			this->Mca->Dock = System::Windows::Forms::DockStyle::Top;
			this->Mca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Mca->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->Mca->Location = System::Drawing::Point(210, 167);
			this->Mca->Multiline = true;
			this->Mca->Name = L"Mca";
			this->Mca->ReadOnly = true;
			this->Mca->Size = System::Drawing::Size(102, 31);
			this->Mca->TabIndex = 19;
			this->Mca->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label37
			// 
			this->label37->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label37->ForeColor = System::Drawing::Color::Gainsboro;
			this->label37->Location = System::Drawing::Point(3, 201);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(201, 37);
			this->label37->TabIndex = 22;
			this->label37->Text = L"Max Color";
			this->label37->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// maxca
			// 
			this->maxca->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->maxca->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->maxca->Cursor = System::Windows::Forms::Cursors::Default;
			this->maxca->Dock = System::Windows::Forms::DockStyle::Top;
			this->maxca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->maxca->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->maxca->Location = System::Drawing::Point(210, 204);
			this->maxca->Multiline = true;
			this->maxca->Name = L"maxca";
			this->maxca->ReadOnly = true;
			this->maxca->Size = System::Drawing::Size(102, 31);
			this->maxca->TabIndex = 21;
			this->maxca->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label38
			// 
			this->label38->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label38->ForeColor = System::Drawing::Color::Gainsboro;
			this->label38->Location = System::Drawing::Point(3, 238);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(201, 37);
			this->label38->TabIndex = 24;
			this->label38->Text = L"Average Color";
			this->label38->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Aca
			// 
			this->Aca->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->Aca->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Aca->Cursor = System::Windows::Forms::Cursors::Default;
			this->Aca->Dock = System::Windows::Forms::DockStyle::Top;
			this->Aca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Aca->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->Aca->Location = System::Drawing::Point(210, 241);
			this->Aca->Multiline = true;
			this->Aca->Name = L"Aca";
			this->Aca->ReadOnly = true;
			this->Aca->Size = System::Drawing::Size(102, 31);
			this->Aca->TabIndex = 23;
			this->Aca->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label39
			// 
			this->label39->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label39->ForeColor = System::Drawing::Color::Gainsboro;
			this->label39->Location = System::Drawing::Point(3, 275);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(201, 37);
			this->label39->TabIndex = 26;
			this->label39->Text = L"Channels";
			this->label39->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ca
			// 
			this->ca->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->ca->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ca->Cursor = System::Windows::Forms::Cursors::Default;
			this->ca->Dock = System::Windows::Forms::DockStyle::Top;
			this->ca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ca->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->ca->Location = System::Drawing::Point(210, 278);
			this->ca->Multiline = true;
			this->ca->Name = L"ca";
			this->ca->ReadOnly = true;
			this->ca->Size = System::Drawing::Size(102, 31);
			this->ca->TabIndex = 25;
			this->ca->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label48
			// 
			this->label48->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label48->ForeColor = System::Drawing::Color::Gainsboro;
			this->label48->Location = System::Drawing::Point(3, 312);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(201, 37);
			this->label48->TabIndex = 28;
			this->label48->Text = L"Depth";
			this->label48->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// da
			// 
			this->da->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->da->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->da->Cursor = System::Windows::Forms::Cursors::Default;
			this->da->Dock = System::Windows::Forms::DockStyle::Top;
			this->da->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->da->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->da->Location = System::Drawing::Point(210, 315);
			this->da->Multiline = true;
			this->da->Name = L"da";
			this->da->ReadOnly = true;
			this->da->Size = System::Drawing::Size(102, 31);
			this->da->TabIndex = 27;
			this->da->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// dbefor
			// 
			this->dbefor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->dbefor->Controls->Add(this->flowLayoutPanel27);
			this->dbefor->Location = System::Drawing::Point(535, 83);
			this->dbefor->Name = L"dbefor";
			this->dbefor->Size = System::Drawing::Size(344, 352);
			this->dbefor->TabIndex = 7;
			this->dbefor->Visible = false;
			this->dbefor->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel3_Paint);
			// 
			// flowLayoutPanel27
			// 
			this->flowLayoutPanel27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel27->Controls->Add(this->panel6);
			this->flowLayoutPanel27->Controls->Add(this->label41);
			this->flowLayoutPanel27->Controls->Add(this->wb);
			this->flowLayoutPanel27->Controls->Add(this->label42);
			this->flowLayoutPanel27->Controls->Add(this->hb);
			this->flowLayoutPanel27->Controls->Add(this->label43);
			this->flowLayoutPanel27->Controls->Add(this->tpb);
			this->flowLayoutPanel27->Controls->Add(this->label44);
			this->flowLayoutPanel27->Controls->Add(this->mcb);
			this->flowLayoutPanel27->Controls->Add(this->label45);
			this->flowLayoutPanel27->Controls->Add(this->maxcb);
			this->flowLayoutPanel27->Controls->Add(this->label46);
			this->flowLayoutPanel27->Controls->Add(this->acb);
			this->flowLayoutPanel27->Controls->Add(this->label47);
			this->flowLayoutPanel27->Controls->Add(this->cb);
			this->flowLayoutPanel27->Controls->Add(this->label49);
			this->flowLayoutPanel27->Controls->Add(this->db);
			this->flowLayoutPanel27->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel27->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel27->Name = L"flowLayoutPanel27";
			this->flowLayoutPanel27->Size = System::Drawing::Size(344, 352);
			this->flowLayoutPanel27->TabIndex = 9;
			this->flowLayoutPanel27->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel27_Paint);
			// 
			// panel6
			// 
			this->panel6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->panel6->Controls->Add(this->label40);
			this->panel6->Controls->Add(this->button21);
			this->panel6->Location = System::Drawing::Point(3, 3);
			this->panel6->Name = L"panel6";
			this->panel6->Padding = System::Windows::Forms::Padding(10, 12, 10, 10);
			this->panel6->Size = System::Drawing::Size(341, 47);
			this->panel6->TabIndex = 7;
			// 
			// label40
			// 
			this->label40->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label40->ForeColor = System::Drawing::Color::Gainsboro;
			this->label40->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label40.Image")));
			this->label40->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label40->Location = System::Drawing::Point(52, 1);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(211, 44);
			this->label40->TabIndex = 15;
			this->label40->Text = L"Details";
			this->label40->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button21
			// 
			this->button21->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button21->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button21.BackgroundImage")));
			this->button21->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button21->FlatAppearance->BorderSize = 0;
			this->button21->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button21->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->button21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button21->Location = System::Drawing::Point(282, 6);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(20, 30);
			this->button21->TabIndex = 8;
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			// 
			// label41
			// 
			this->label41->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label41->ForeColor = System::Drawing::Color::Gainsboro;
			this->label41->Location = System::Drawing::Point(3, 53);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(201, 37);
			this->label41->TabIndex = 15;
			this->label41->Text = L"Width";
			this->label41->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// wb
			// 
			this->wb->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->wb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->wb->Cursor = System::Windows::Forms::Cursors::Default;
			this->wb->Dock = System::Windows::Forms::DockStyle::Top;
			this->wb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->wb->Location = System::Drawing::Point(210, 56);
			this->wb->Multiline = true;
			this->wb->Name = L"wb";
			this->wb->ReadOnly = true;
			this->wb->Size = System::Drawing::Size(102, 31);
			this->wb->TabIndex = 11;
			this->wb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label42
			// 
			this->label42->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label42->ForeColor = System::Drawing::Color::Gainsboro;
			this->label42->Location = System::Drawing::Point(3, 90);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(201, 37);
			this->label42->TabIndex = 16;
			this->label42->Text = L"Hight";
			this->label42->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// hb
			// 
			this->hb->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->hb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->hb->Cursor = System::Windows::Forms::Cursors::Default;
			this->hb->Dock = System::Windows::Forms::DockStyle::Top;
			this->hb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->hb->Location = System::Drawing::Point(210, 93);
			this->hb->Multiline = true;
			this->hb->Name = L"hb";
			this->hb->ReadOnly = true;
			this->hb->Size = System::Drawing::Size(102, 31);
			this->hb->TabIndex = 12;
			this->hb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label43
			// 
			this->label43->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label43->ForeColor = System::Drawing::Color::Gainsboro;
			this->label43->Location = System::Drawing::Point(3, 127);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(201, 37);
			this->label43->TabIndex = 18;
			this->label43->Text = L"Total Px";
			this->label43->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tpb
			// 
			this->tpb->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->tpb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tpb->Cursor = System::Windows::Forms::Cursors::Default;
			this->tpb->Dock = System::Windows::Forms::DockStyle::Top;
			this->tpb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tpb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->tpb->Location = System::Drawing::Point(210, 130);
			this->tpb->Multiline = true;
			this->tpb->Name = L"tpb";
			this->tpb->ReadOnly = true;
			this->tpb->Size = System::Drawing::Size(102, 31);
			this->tpb->TabIndex = 17;
			this->tpb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label44
			// 
			this->label44->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label44->ForeColor = System::Drawing::Color::Gainsboro;
			this->label44->Location = System::Drawing::Point(3, 164);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(201, 37);
			this->label44->TabIndex = 20;
			this->label44->Text = L"Min Color";
			this->label44->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// mcb
			// 
			this->mcb->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->mcb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mcb->Cursor = System::Windows::Forms::Cursors::Default;
			this->mcb->Dock = System::Windows::Forms::DockStyle::Top;
			this->mcb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mcb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->mcb->Location = System::Drawing::Point(210, 167);
			this->mcb->Multiline = true;
			this->mcb->Name = L"mcb";
			this->mcb->ReadOnly = true;
			this->mcb->Size = System::Drawing::Size(102, 31);
			this->mcb->TabIndex = 19;
			this->mcb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label45
			// 
			this->label45->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label45->ForeColor = System::Drawing::Color::Gainsboro;
			this->label45->Location = System::Drawing::Point(3, 201);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(201, 37);
			this->label45->TabIndex = 22;
			this->label45->Text = L"Max Color";
			this->label45->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// maxcb
			// 
			this->maxcb->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->maxcb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->maxcb->Cursor = System::Windows::Forms::Cursors::Default;
			this->maxcb->Dock = System::Windows::Forms::DockStyle::Top;
			this->maxcb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->maxcb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->maxcb->Location = System::Drawing::Point(210, 204);
			this->maxcb->Multiline = true;
			this->maxcb->Name = L"maxcb";
			this->maxcb->ReadOnly = true;
			this->maxcb->Size = System::Drawing::Size(102, 31);
			this->maxcb->TabIndex = 21;
			this->maxcb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label46
			// 
			this->label46->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label46->ForeColor = System::Drawing::Color::Gainsboro;
			this->label46->Location = System::Drawing::Point(3, 238);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(201, 37);
			this->label46->TabIndex = 24;
			this->label46->Text = L"Average Color";
			this->label46->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// acb
			// 
			this->acb->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->acb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->acb->Cursor = System::Windows::Forms::Cursors::Default;
			this->acb->Dock = System::Windows::Forms::DockStyle::Top;
			this->acb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->acb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->acb->Location = System::Drawing::Point(210, 241);
			this->acb->Multiline = true;
			this->acb->Name = L"acb";
			this->acb->ReadOnly = true;
			this->acb->Size = System::Drawing::Size(102, 31);
			this->acb->TabIndex = 23;
			this->acb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label47
			// 
			this->label47->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label47->ForeColor = System::Drawing::Color::Gainsboro;
			this->label47->Location = System::Drawing::Point(3, 275);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(201, 37);
			this->label47->TabIndex = 26;
			this->label47->Text = L"Channels";
			this->label47->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cb
			// 
			this->cb->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->cb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cb->Cursor = System::Windows::Forms::Cursors::Default;
			this->cb->Dock = System::Windows::Forms::DockStyle::Top;
			this->cb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->cb->Location = System::Drawing::Point(210, 278);
			this->cb->Multiline = true;
			this->cb->Name = L"cb";
			this->cb->ReadOnly = true;
			this->cb->Size = System::Drawing::Size(102, 31);
			this->cb->TabIndex = 25;
			this->cb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label49
			// 
			this->label49->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label49->ForeColor = System::Drawing::Color::Gainsboro;
			this->label49->Location = System::Drawing::Point(3, 312);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(201, 37);
			this->label49->TabIndex = 28;
			this->label49->Text = L"Depth";
			this->label49->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// db
			// 
			this->db->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->db->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->db->Cursor = System::Windows::Forms::Cursors::Default;
			this->db->Dock = System::Windows::Forms::DockStyle::Top;
			this->db->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->db->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->db->Location = System::Drawing::Point(210, 315);
			this->db->Multiline = true;
			this->db->Name = L"db";
			this->db->ReadOnly = true;
			this->db->Size = System::Drawing::Size(102, 31);
			this->db->TabIndex = 27;
			this->db->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->db->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged_2);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(-40, 0);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(112, 83);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 7;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &MyForm::pictureBox3_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->pictureBox2->Location = System::Drawing::Point(430, 94);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(339, 377);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			// 
			// infoa
			// 
			this->infoa->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->infoa->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->infoa->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->infoa->ForeColor = System::Drawing::Color::DodgerBlue;
			this->infoa->Location = System::Drawing::Point(433, 438);
			this->infoa->Multiline = true;
			this->infoa->Name = L"infoa";
			this->infoa->Size = System::Drawing::Size(231, 37);
			this->infoa->TabIndex = 13;
			this->infoa->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->infoa->TextChanged += gcnew System::EventHandler(this, &MyForm::infoa_TextChanged);
			// 
			// button17
			// 
			this->button17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->button17->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button17->FlatAppearance->BorderSize = 0;
			this->button17->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button17->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button17->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->button17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button17.Image")));
			this->button17->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button17->Location = System::Drawing::Point(704, 7);
			this->button17->Name = L"button17";
			this->button17->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->button17->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button17->Size = System::Drawing::Size(175, 81);
			this->button17->TabIndex = 5;
			this->button17->Text = L"OPEN IMAGE";
			this->button17->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// befor
			// 
			this->befor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->befor->Controls->Add(this->infob);
			this->befor->Controls->Add(this->pictureBox1);
			this->befor->Controls->Add(this->title);
			this->befor->Dock = System::Windows::Forms::DockStyle::Fill;
			this->befor->Location = System::Drawing::Point(0, 0);
			this->befor->Name = L"befor";
			this->befor->Size = System::Drawing::Size(1263, 660);
			this->befor->TabIndex = 5;
			this->befor->Visible = false;
			this->befor->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::befor_Paint);
			// 
			// infob
			// 
			this->infob->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->infob->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->infob->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->infob->ForeColor = System::Drawing::Color::DodgerBlue;
			this->infob->Location = System::Drawing::Point(918, 441);
			this->infob->Multiline = true;
			this->infob->Name = L"infob";
			this->infob->Size = System::Drawing::Size(203, 32);
			this->infob->TabIndex = 12;
			this->infob->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->infob->TextChanged += gcnew System::EventHandler(this, &MyForm::infob_TextChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(876, 94);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(339, 377);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// title
			// 
			this->title->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->title->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->title->Controls->Add(this->button22);
			this->title->Controls->Add(this->label20);
			this->title->Controls->Add(this->button19);
			this->title->Location = System::Drawing::Point(891, 28);
			this->title->Name = L"title";
			this->title->Padding = System::Windows::Forms::Padding(10, 12, 10, 10);
			this->title->Size = System::Drawing::Size(314, 47);
			this->title->TabIndex = 6;
			// 
			// button22
			// 
			this->button22->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button22->FlatAppearance->BorderSize = 0;
			this->button22->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button22->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button22->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button22->ForeColor = System::Drawing::Color::Gainsboro;
			this->button22->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button22.Image")));
			this->button22->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button22->Location = System::Drawing::Point(13, 6);
			this->button22->Name = L"button22";
			this->button22->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->button22->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button22->Size = System::Drawing::Size(52, 41);
			this->button22->TabIndex = 8;
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			// 
			// label20
			// 
			this->label20->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::Gainsboro;
			this->label20->Location = System::Drawing::Point(51, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(186, 44);
			this->label20->TabIndex = 8;
			this->label20->Text = L"Original";
			this->label20->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button19
			// 
			this->button19->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button19->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button19.BackgroundImage")));
			this->button19->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button19->FlatAppearance->BorderSize = 0;
			this->button19->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button19->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button19->Location = System::Drawing::Point(269, 6);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(20, 30);
			this->button19->TabIndex = 8;
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// Histogram
			// 
			this->Histogram->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->Histogram->Controls->Add(this->histogramtextBox);
			this->Histogram->Controls->Add(this->label66);
			this->Histogram->Controls->Add(this->panel18);
			this->Histogram->Controls->Add(this->pictureBox4);
			this->Histogram->Location = System::Drawing::Point(388, 494);
			this->Histogram->Name = L"Histogram";
			this->Histogram->Size = System::Drawing::Size(857, 151);
			this->Histogram->TabIndex = 15;
			this->Histogram->Visible = false;
			this->Histogram->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint_1);
			// 
			// histogramtextBox
			// 
			this->histogramtextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->histogramtextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->histogramtextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->histogramtextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->histogramtextBox->Location = System::Drawing::Point(3, 97);
			this->histogramtextBox->Multiline = true;
			this->histogramtextBox->Name = L"histogramtextBox";
			this->histogramtextBox->Size = System::Drawing::Size(130, 40);
			this->histogramtextBox->TabIndex = 30;
			this->histogramtextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->histogramtextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::histogramtextBox_TextChanged);
			// 
			// label66
			// 
			this->label66->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label66->ForeColor = System::Drawing::Color::Gainsboro;
			this->label66->Location = System::Drawing::Point(3, 58);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(130, 37);
			this->label66->TabIndex = 29;
			this->label66->Text = L"Intansity";
			this->label66->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panel18
			// 
			this->panel18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->panel18->Controls->Add(this->label65);
			this->panel18->Controls->Add(this->button33);
			this->panel18->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel18->Location = System::Drawing::Point(0, 0);
			this->panel18->Name = L"panel18";
			this->panel18->Padding = System::Windows::Forms::Padding(10, 12, 10, 10);
			this->panel18->Size = System::Drawing::Size(857, 47);
			this->panel18->TabIndex = 15;
			// 
			// label65
			// 
			this->label65->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label65->ForeColor = System::Drawing::Color::Gainsboro;
			this->label65->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label65.Image")));
			this->label65->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label65->Location = System::Drawing::Point(13, 5);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(258, 44);
			this->label65->TabIndex = 8;
			this->label65->Text = L"Histogram";
			this->label65->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label65->Click += gcnew System::EventHandler(this, &MyForm::label65_Click_1);
			// 
			// button33
			// 
			this->button33->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button33->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button33.BackgroundImage")));
			this->button33->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button33->FlatAppearance->BorderSize = 0;
			this->button33->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button33->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->button33->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button33->Location = System::Drawing::Point(824, 12);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(20, 30);
			this->button33->TabIndex = 8;
			this->button33->UseVisualStyleBackColor = true;
			this->button33->Click += gcnew System::EventHandler(this, &MyForm::button33_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(139, 41);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(715, 100);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 14;
			this->pictureBox4->TabStop = false;
			// 
			// button18
			// 
			this->button18->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->button18->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button18.BackgroundImage")));
			this->button18->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button18->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button18->FlatAppearance->BorderSize = 0;
			this->button18->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button18->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button18->Location = System::Drawing::Point(3, 47);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(126, 27);
			this->button18->TabIndex = 7;
			this->button18->UseVisualStyleBackColor = false;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click_1);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(135, 47);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(151, 33);
			this->button3->TabIndex = 6;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_2);
			// 
			// sour
			// 
			this->sour->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->sour->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sour->ForeColor = System::Drawing::Color::Gainsboro;
			this->sour->Location = System::Drawing::Point(595, 4);
			this->sour->Name = L"sour";
			this->sour->Size = System::Drawing::Size(666, 39);
			this->sour->TabIndex = 9;
			this->sour->Text = L"Source";
			this->sour->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// edit
			// 
			this->edit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->edit->Controls->Add(this->T);
			this->edit->Controls->Add(this->flowLayoutPanel2);
			this->edit->Location = System::Drawing::Point(0, 0);
			this->edit->Name = L"edit";
			this->edit->Padding = System::Windows::Forms::Padding(10, 10, 0, 10);
			this->edit->Size = System::Drawing::Size(308, 728);
			this->edit->TabIndex = 3;
			this->edit->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::edit_Paint);
			// 
			// T
			// 
			this->T->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->T->Controls->Add(this->label1);
			this->T->Controls->Add(this->button6);
			this->T->Location = System::Drawing::Point(0, 0);
			this->T->Name = L"T";
			this->T->Padding = System::Windows::Forms::Padding(10, 12, 10, 10);
			this->T->Size = System::Drawing::Size(314, 47);
			this->T->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Gainsboro;
			this->label1->Location = System::Drawing::Point(51, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(186, 44);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Edit";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button6
			// 
			this->button6->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.BackgroundImage")));
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Location = System::Drawing::Point(269, 6);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(20, 30);
			this->button6->TabIndex = 8;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click_2);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->AutoScroll = true;
			this->flowLayoutPanel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel2->Controls->Add(this->sk);
			this->flowLayoutPanel2->Controls->Add(this->Rotate);
			this->flowLayoutPanel2->Controls->Add(this->zoom);
			this->flowLayoutPanel2->Controls->Add(this->clip);
			this->flowLayoutPanel2->Controls->Add(this->resize);
			this->flowLayoutPanel2->Controls->Add(this->flip);
			this->flowLayoutPanel2->Location = System::Drawing::Point(16, 53);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(317, 679);
			this->flowLayoutPanel2->TabIndex = 8;
			this->flowLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel2_Paint);
			// 
			// sk
			// 
			this->sk->Controls->Add(this->flowLayoutPanel24);
			this->sk->Dock = System::Windows::Forms::DockStyle::Top;
			this->sk->Location = System::Drawing::Point(3, 3);
			this->sk->Name = L"sk";
			this->sk->Size = System::Drawing::Size(299, 89);
			this->sk->TabIndex = 15;
			// 
			// flowLayoutPanel24
			// 
			this->flowLayoutPanel24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel24->Controls->Add(this->label23);
			this->flowLayoutPanel24->Controls->Add(this->label31);
			this->flowLayoutPanel24->Controls->Add(this->trackBar19);
			this->flowLayoutPanel24->Controls->Add(this->label32);
			this->flowLayoutPanel24->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel24->Name = L"flowLayoutPanel24";
			this->flowLayoutPanel24->Size = System::Drawing::Size(299, 87);
			this->flowLayoutPanel24->TabIndex = 8;
			// 
			// label23
			// 
			this->label23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->label23->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::Color::Gainsboro;
			this->label23->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label23.Image")));
			this->label23->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label23->Location = System::Drawing::Point(3, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(276, 44);
			this->label23->TabIndex = 15;
			this->label23->Text = L"Skew";
			this->label23->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label31
			// 
			this->label31->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->ForeColor = System::Drawing::Color::Gainsboro;
			this->label31->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label31.Image")));
			this->label31->Location = System::Drawing::Point(3, 44);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(49, 44);
			this->label31->TabIndex = 20;
			this->label31->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label32
			// 
			this->label32->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->ForeColor = System::Drawing::Color::Gainsboro;
			this->label32->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label32.Image")));
			this->label32->Location = System::Drawing::Point(244, 44);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(29, 44);
			this->label32->TabIndex = 19;
			this->label32->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Rotate
			// 
			this->Rotate->Controls->Add(this->flowLayoutPanel4);
			this->Rotate->Dock = System::Windows::Forms::DockStyle::Top;
			this->Rotate->Location = System::Drawing::Point(3, 98);
			this->Rotate->Name = L"Rotate";
			this->Rotate->Size = System::Drawing::Size(299, 131);
			this->Rotate->TabIndex = 10;
			// 
			// flowLayoutPanel4
			// 
			this->flowLayoutPanel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel4->Controls->Add(this->label2);
			this->flowLayoutPanel4->Controls->Add(this->rl);
			this->flowLayoutPanel4->Controls->Add(this->rr);
			this->flowLayoutPanel4->Controls->Add(this->label18);
			this->flowLayoutPanel4->Controls->Add(this->trackBar6);
			this->flowLayoutPanel4->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			this->flowLayoutPanel4->Size = System::Drawing::Size(299, 168);
			this->flowLayoutPanel4->TabIndex = 8;
			this->flowLayoutPanel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel4_Paint);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Gainsboro;
			this->label2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label2.Image")));
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label2->Location = System::Drawing::Point(3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(282, 44);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Rotate";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label18
			// 
			this->label18->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::Color::Gainsboro;
			this->label18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label18.Image")));
			this->label18->Location = System::Drawing::Point(3, 94);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(42, 34);
			this->label18->TabIndex = 22;
			this->label18->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// zoom
			// 
			this->zoom->Controls->Add(this->flowLayoutPanel14);
			this->zoom->Dock = System::Windows::Forms::DockStyle::Top;
			this->zoom->Location = System::Drawing::Point(3, 235);
			this->zoom->Name = L"zoom";
			this->zoom->Size = System::Drawing::Size(299, 90);
			this->zoom->TabIndex = 14;
			// 
			// flowLayoutPanel14
			// 
			this->flowLayoutPanel14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel14->Controls->Add(this->label15);
			this->flowLayoutPanel14->Controls->Add(this->label16);
			this->flowLayoutPanel14->Controls->Add(this->trackBar11);
			this->flowLayoutPanel14->Controls->Add(this->label17);
			this->flowLayoutPanel14->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel14->Name = L"flowLayoutPanel14";
			this->flowLayoutPanel14->Size = System::Drawing::Size(299, 104);
			this->flowLayoutPanel14->TabIndex = 8;
			// 
			// label15
			// 
			this->label15->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::Gainsboro;
			this->label15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label15.Image")));
			this->label15->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label15->Location = System::Drawing::Point(3, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(253, 44);
			this->label15->TabIndex = 15;
			this->label15->Text = L"Zoom";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label16
			// 
			this->label16->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::Gainsboro;
			this->label16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label16.Image")));
			this->label16->Location = System::Drawing::Point(3, 44);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(49, 44);
			this->label16->TabIndex = 20;
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label16->Click += gcnew System::EventHandler(this, &MyForm::label16_Click);
			// 
			// label17
			// 
			this->label17->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::Gainsboro;
			this->label17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label17.Image")));
			this->label17->Location = System::Drawing::Point(244, 44);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(29, 44);
			this->label17->TabIndex = 19;
			this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// clip
			// 
			this->clip->Controls->Add(this->flowLayoutPanel12);
			this->clip->Dock = System::Windows::Forms::DockStyle::Top;
			this->clip->Location = System::Drawing::Point(3, 331);
			this->clip->Name = L"clip";
			this->clip->Size = System::Drawing::Size(299, 122);
			this->clip->TabIndex = 12;
			// 
			// flowLayoutPanel12
			// 
			this->flowLayoutPanel12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel12->Controls->Add(this->label8);
			this->flowLayoutPanel12->Controls->Add(this->label12);
			this->flowLayoutPanel12->Controls->Add(this->trackBar7);
			this->flowLayoutPanel12->Controls->Add(this->label11);
			this->flowLayoutPanel12->Controls->Add(this->trackBar10);
			this->flowLayoutPanel12->Location = System::Drawing::Point(0, -4);
			this->flowLayoutPanel12->Name = L"flowLayoutPanel12";
			this->flowLayoutPanel12->Size = System::Drawing::Size(299, 129);
			this->flowLayoutPanel12->TabIndex = 8;
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Gainsboro;
			this->label8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label8.Image")));
			this->label8->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label8->Location = System::Drawing::Point(3, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(276, 44);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Clip";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Gainsboro;
			this->label12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label12.Image")));
			this->label12->Location = System::Drawing::Point(3, 44);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(67, 44);
			this->label12->TabIndex = 20;
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label11
			// 
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Gainsboro;
			this->label11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label11.Image")));
			this->label11->Location = System::Drawing::Point(3, 88);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(67, 44);
			this->label11->TabIndex = 19;
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// resize
			// 
			this->resize->Controls->Add(this->flowLayoutPanel13);
			this->resize->Dock = System::Windows::Forms::DockStyle::Top;
			this->resize->Location = System::Drawing::Point(3, 459);
			this->resize->Name = L"resize";
			this->resize->Size = System::Drawing::Size(299, 124);
			this->resize->TabIndex = 13;
			// 
			// flowLayoutPanel13
			// 
			this->flowLayoutPanel13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel13->Controls->Add(this->label10);
			this->flowLayoutPanel13->Controls->Add(this->label13);
			this->flowLayoutPanel13->Controls->Add(this->trackBar8);
			this->flowLayoutPanel13->Controls->Add(this->label14);
			this->flowLayoutPanel13->Controls->Add(this->trackBar9);
			this->flowLayoutPanel13->Location = System::Drawing::Point(0, -4);
			this->flowLayoutPanel13->Name = L"flowLayoutPanel13";
			this->flowLayoutPanel13->Size = System::Drawing::Size(299, 125);
			this->flowLayoutPanel13->TabIndex = 8;
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Gainsboro;
			this->label10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label10.Image")));
			this->label10->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label10->Location = System::Drawing::Point(3, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(282, 44);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Resize";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Gainsboro;
			this->label13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label13.Image")));
			this->label13->Location = System::Drawing::Point(3, 44);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(67, 44);
			this->label13->TabIndex = 20;
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label14
			// 
			this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::Gainsboro;
			this->label14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label14.Image")));
			this->label14->Location = System::Drawing::Point(3, 88);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(67, 34);
			this->label14->TabIndex = 19;
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// flip
			// 
			this->flip->Controls->Add(this->flowLayoutPanel5);
			this->flip->Dock = System::Windows::Forms::DockStyle::Top;
			this->flip->Location = System::Drawing::Point(3, 589);
			this->flip->Name = L"flip";
			this->flip->Size = System::Drawing::Size(299, 101);
			this->flip->TabIndex = 11;
			this->flip->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flip_Paint);
			// 
			// flowLayoutPanel5
			// 
			this->flowLayoutPanel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel5->Controls->Add(this->label3);
			this->flowLayoutPanel5->Controls->Add(this->button5);
			this->flowLayoutPanel5->Controls->Add(this->button4);
			this->flowLayoutPanel5->Location = System::Drawing::Point(0, -3);
			this->flowLayoutPanel5->Name = L"flowLayoutPanel5";
			this->flowLayoutPanel5->Size = System::Drawing::Size(299, 106);
			this->flowLayoutPanel5->TabIndex = 8;
			this->flowLayoutPanel5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel5_Paint);
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Gainsboro;
			this->label3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label3.Image")));
			this->label3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label3->Location = System::Drawing::Point(3, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(286, 44);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Mirror";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// done
			// 
			this->done->FlatAppearance->BorderColor = System::Drawing::SystemColors::MenuHighlight;
			this->done->FlatAppearance->BorderSize = 0;
			this->done->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->done->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->done->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->done->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.125F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->done->ForeColor = System::Drawing::Color::Gainsboro;
			this->done->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"done.Image")));
			this->done->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->done->Location = System::Drawing::Point(0, 662);
			this->done->Name = L"done";
			this->done->Size = System::Drawing::Size(182, 53);
			this->done->TabIndex = 9;
			this->done->Text = L"Done";
			this->done->UseVisualStyleBackColor = true;
			this->done->Click += gcnew System::EventHandler(this, &MyForm::button16_Click_1);
			// 
			// top
			// 
			this->top->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->top->Controls->Add(this->button1);
			this->top->Controls->Add(this->sour);
			this->top->Controls->Add(this->max);
			this->top->Controls->Add(this->close);
			this->top->Controls->Add(this->min);
			this->top->Dock = System::Windows::Forms::DockStyle::Top;
			this->top->Location = System::Drawing::Point(0, 0);
			this->top->Name = L"top";
			this->top->Size = System::Drawing::Size(1448, 39);
			this->top->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(12, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(29, 33);
			this->button1->TabIndex = 5;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_2);
			// 
			// max
			// 
			this->max->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->max->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"max.BackgroundImage")));
			this->max->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->max->FlatAppearance->BorderSize = 0;
			this->max->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->max->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->max->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->max->Location = System::Drawing::Point(1367, 3);
			this->max->Name = L"max";
			this->max->Size = System::Drawing::Size(23, 30);
			this->max->TabIndex = 2;
			this->max->UseVisualStyleBackColor = true;
			this->max->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// close
			// 
			this->close->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->close->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close.BackgroundImage")));
			this->close->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->close->FlatAppearance->BorderSize = 0;
			this->close->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->close->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close->Location = System::Drawing::Point(1416, 3);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(20, 30);
			this->close->TabIndex = 4;
			this->close->UseVisualStyleBackColor = true;
			this->close->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// min
			// 
			this->min->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->min->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"min.BackgroundImage")));
			this->min->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->min->FlatAppearance->BorderSize = 0;
			this->min->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->min->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->min->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->min->Location = System::Drawing::Point(1313, 4);
			this->min->Name = L"min";
			this->min->Size = System::Drawing::Size(19, 30);
			this->min->TabIndex = 1;
			this->min->UseVisualStyleBackColor = true;
			this->min->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// manue
			// 
			this->manue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->manue->Controls->Add(this->flowLayoutPanel1);
			this->manue->Controls->Add(this->done);
			this->manue->Dock = System::Windows::Forms::DockStyle::Left;
			this->manue->Location = System::Drawing::Point(0, 39);
			this->manue->Name = L"manue";
			this->manue->Size = System::Drawing::Size(185, 732);
			this->manue->TabIndex = 1;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel1->Controls->Add(this->hom);
			this->flowLayoutPanel1->Controls->Add(this->CandR);
			this->flowLayoutPanel1->Controls->Add(this->Adj);
			this->flowLayoutPanel1->Controls->Add(this->Fil);
			this->flowLayoutPanel1->Controls->Add(this->Blu);
			this->flowLayoutPanel1->Controls->Add(this->button9);
			this->flowLayoutPanel1->Controls->Add(this->dtct);
			this->flowLayoutPanel1->Controls->Add(this->button15);
			this->flowLayoutPanel1->Controls->Add(this->button26);
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(185, 645);
			this->flowLayoutPanel1->TabIndex = 1;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel1_Paint);
			// 
			// hom
			// 
			this->hom->Cursor = System::Windows::Forms::Cursors::Hand;
			this->hom->FlatAppearance->BorderSize = 0;
			this->hom->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->hom->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->hom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->hom->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hom->ForeColor = System::Drawing::Color::Gainsboro;
			this->hom->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hom.Image")));
			this->hom->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->hom->Location = System::Drawing::Point(3, 3);
			this->hom->Name = L"hom";
			this->hom->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->hom->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->hom->Size = System::Drawing::Size(179, 72);
			this->hom->TabIndex = 4;
			this->hom->Text = L"Home";
			this->hom->UseVisualStyleBackColor = true;
			this->hom->Click += gcnew System::EventHandler(this, &MyForm::hom_Click);
			// 
			// CandR
			// 
			this->CandR->Cursor = System::Windows::Forms::Cursors::Hand;
			this->CandR->FlatAppearance->BorderSize = 0;
			this->CandR->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->CandR->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->CandR->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CandR->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CandR->ForeColor = System::Drawing::Color::Gainsboro;
			this->CandR->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CandR.Image")));
			this->CandR->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->CandR->Location = System::Drawing::Point(3, 81);
			this->CandR->Name = L"CandR";
			this->CandR->Padding = System::Windows::Forms::Padding(3, 6, 3, 3);
			this->CandR->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->CandR->Size = System::Drawing::Size(176, 60);
			this->CandR->TabIndex = 0;
			this->CandR->Text = L"Edit";
			this->CandR->UseVisualStyleBackColor = true;
			this->CandR->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// Adj
			// 
			this->Adj->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Adj->FlatAppearance->BorderSize = 0;
			this->Adj->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->Adj->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->Adj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Adj->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Adj->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->Adj->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Adj.Image")));
			this->Adj->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Adj->Location = System::Drawing::Point(3, 147);
			this->Adj->Name = L"Adj";
			this->Adj->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->Adj->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Adj->Size = System::Drawing::Size(179, 64);
			this->Adj->TabIndex = 1;
			this->Adj->Text = L"Adjust";
			this->Adj->UseVisualStyleBackColor = true;
			this->Adj->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// Fil
			// 
			this->Fil->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Fil->FlatAppearance->BorderSize = 0;
			this->Fil->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->Fil->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->Fil->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Fil->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Fil->ForeColor = System::Drawing::Color::Gainsboro;
			this->Fil->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Fil.Image")));
			this->Fil->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Fil->Location = System::Drawing::Point(3, 217);
			this->Fil->Name = L"Fil";
			this->Fil->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->Fil->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Fil->Size = System::Drawing::Size(176, 60);
			this->Fil->TabIndex = 2;
			this->Fil->Text = L"Filter";
			this->Fil->UseVisualStyleBackColor = true;
			this->Fil->Click += gcnew System::EventHandler(this, &MyForm::button6_Click_1);
			// 
			// Blu
			// 
			this->Blu->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Blu->FlatAppearance->BorderSize = 0;
			this->Blu->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->Blu->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->Blu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Blu->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Blu->ForeColor = System::Drawing::Color::Gainsboro;
			this->Blu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Blu.Image")));
			this->Blu->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Blu->Location = System::Drawing::Point(3, 283);
			this->Blu->Name = L"Blu";
			this->Blu->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->Blu->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Blu->Size = System::Drawing::Size(182, 66);
			this->Blu->TabIndex = 3;
			this->Blu->Text = L"Effect";
			this->Blu->UseVisualStyleBackColor = true;
			this->Blu->Click += gcnew System::EventHandler(this, &MyForm::Blu_Click);
			// 
			// button9
			// 
			this->button9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button9->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::Gainsboro;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.Image")));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button9->Location = System::Drawing::Point(3, 355);
			this->button9->Name = L"button9";
			this->button9->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->button9->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button9->Size = System::Drawing::Size(182, 66);
			this->button9->TabIndex = 5;
			this->button9->Text = L"Liquify";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// dtct
			// 
			this->dtct->Cursor = System::Windows::Forms::Cursors::Hand;
			this->dtct->FlatAppearance->BorderSize = 0;
			this->dtct->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->dtct->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->dtct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dtct->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dtct->ForeColor = System::Drawing::Color::Gainsboro;
			this->dtct->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dtct.Image")));
			this->dtct->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->dtct->Location = System::Drawing::Point(3, 427);
			this->dtct->Name = L"dtct";
			this->dtct->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->dtct->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->dtct->Size = System::Drawing::Size(182, 66);
			this->dtct->TabIndex = 6;
			this->dtct->Text = L"Detect";
			this->dtct->UseVisualStyleBackColor = true;
			this->dtct->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button15
			// 
			this->button15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button15->FlatAppearance->BorderSize = 0;
			this->button15->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button15->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->ForeColor = System::Drawing::Color::Gainsboro;
			this->button15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button15.Image")));
			this->button15->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button15->Location = System::Drawing::Point(3, 499);
			this->button15->Name = L"button15";
			this->button15->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->button15->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button15->Size = System::Drawing::Size(182, 66);
			this->button15->TabIndex = 7;
			this->button15->Text = L"About";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button26
			// 
			this->button26->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button26->FlatAppearance->BorderSize = 0;
			this->button26->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button26->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button26->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button26->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button26->ForeColor = System::Drawing::Color::Gainsboro;
			this->button26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button26.Image")));
			this->button26->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button26->Location = System::Drawing::Point(3, 571);
			this->button26->Name = L"button26";
			this->button26->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->button26->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button26->Size = System::Drawing::Size(182, 60);
			this->button26->TabIndex = 8;
			this->button26->Text = L"Histogram";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
			// 
			// center
			// 
			this->center->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->center->Controls->Add(this->detect);
			this->center->Controls->Add(this->Effect);
			this->center->Controls->Add(this->filters);
			this->center->Controls->Add(this->liquify);
			this->center->Controls->Add(this->adjust);
			this->center->Controls->Add(this->edit);
			this->center->Controls->Add(this->home);
			this->center->Dock = System::Windows::Forms::DockStyle::Fill;
			this->center->Location = System::Drawing::Point(185, 39);
			this->center->Name = L"center";
			this->center->Size = System::Drawing::Size(1263, 660);
			this->center->TabIndex = 8;
			// 
			// detect
			// 
			this->detect->Controls->Add(this->panel2);
			this->detect->Controls->Add(this->flowLayoutPanel32);
			this->detect->Location = System::Drawing::Point(0, 0);
			this->detect->Name = L"detect";
			this->detect->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->detect->Size = System::Drawing::Size(308, 728);
			this->detect->TabIndex = 6;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->panel2->Controls->Add(this->label54);
			this->panel2->Controls->Add(this->button29);
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Padding = System::Windows::Forms::Padding(10, 12, 10, 10);
			this->panel2->Size = System::Drawing::Size(314, 47);
			this->panel2->TabIndex = 5;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel2_Paint);
			// 
			// label54
			// 
			this->label54->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label54->ForeColor = System::Drawing::Color::Gainsboro;
			this->label54->Location = System::Drawing::Point(51, 0);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(186, 44);
			this->label54->TabIndex = 8;
			this->label54->Text = L"Detect";
			this->label54->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button29
			// 
			this->button29->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button29->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button29.BackgroundImage")));
			this->button29->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button29->FlatAppearance->BorderSize = 0;
			this->button29->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button29->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->button29->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button29->Location = System::Drawing::Point(269, 6);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(20, 30);
			this->button29->TabIndex = 8;
			this->button29->UseVisualStyleBackColor = true;
			this->button29->Click += gcnew System::EventHandler(this, &MyForm::button29_Click);
			// 
			// flowLayoutPanel32
			// 
			this->flowLayoutPanel32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel32->Controls->Add(this->panel11);
			this->flowLayoutPanel32->Controls->Add(this->panel12);
			this->flowLayoutPanel32->Controls->Add(this->panel14);
			this->flowLayoutPanel32->Location = System::Drawing::Point(16, 53);
			this->flowLayoutPanel32->Name = L"flowLayoutPanel32";
			this->flowLayoutPanel32->Size = System::Drawing::Size(321, 350);
			this->flowLayoutPanel32->TabIndex = 9;
			// 
			// panel11
			// 
			this->panel11->Controls->Add(this->flowLayoutPanel33);
			this->panel11->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel11->Location = System::Drawing::Point(3, 3);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(317, 128);
			this->panel11->TabIndex = 13;
			// 
			// flowLayoutPanel33
			// 
			this->flowLayoutPanel33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel33->Controls->Add(this->button30);
			this->flowLayoutPanel33->Controls->Add(this->label60);
			this->flowLayoutPanel33->Controls->Add(this->textBox1);
			this->flowLayoutPanel33->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel33->Name = L"flowLayoutPanel33";
			this->flowLayoutPanel33->Size = System::Drawing::Size(299, 125);
			this->flowLayoutPanel33->TabIndex = 8;
			// 
			// button30
			// 
			this->button30->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button30->FlatAppearance->BorderSize = 0;
			this->button30->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button30->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button30->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button30->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold));
			this->button30->ForeColor = System::Drawing::Color::Gainsboro;
			this->button30->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button30.Image")));
			this->button30->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button30->Location = System::Drawing::Point(3, 3);
			this->button30->Name = L"button30";
			this->button30->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->button30->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button30->Size = System::Drawing::Size(282, 68);
			this->button30->TabIndex = 17;
			this->button30->Text = L"Detection";
			this->button30->UseVisualStyleBackColor = true;
			this->button30->Click += gcnew System::EventHandler(this, &MyForm::button30_Click);
			// 
			// label60
			// 
			this->label60->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label60->ForeColor = System::Drawing::Color::Gainsboro;
			this->label60->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label60.Image")));
			this->label60->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label60->Location = System::Drawing::Point(3, 74);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(154, 44);
			this->label60->TabIndex = 32;
			this->label60->Text = L"Shapes";
			this->label60->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label60->Click += gcnew System::EventHandler(this, &MyForm::label60_Click_1);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Default;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::DodgerBlue;
			this->textBox1->Location = System::Drawing::Point(163, 77);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(111, 43);
			this->textBox1->TabIndex = 31;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->flowLayoutPanel34);
			this->panel12->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel12->Location = System::Drawing::Point(3, 137);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(317, 211);
			this->panel12->TabIndex = 14;
			// 
			// flowLayoutPanel34
			// 
			this->flowLayoutPanel34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel34->Controls->Add(this->label58);
			this->flowLayoutPanel34->Controls->Add(this->label59);
			this->flowLayoutPanel34->Controls->Add(this->trackBar24);
			this->flowLayoutPanel34->Controls->Add(this->button32);
			this->flowLayoutPanel34->Controls->Add(this->button35);
			this->flowLayoutPanel34->Controls->Add(this->button34);
			this->flowLayoutPanel34->Controls->Add(this->button36);
			this->flowLayoutPanel34->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel34->Name = L"flowLayoutPanel34";
			this->flowLayoutPanel34->Size = System::Drawing::Size(299, 205);
			this->flowLayoutPanel34->TabIndex = 8;
			this->flowLayoutPanel34->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel34_Paint);
			// 
			// label58
			// 
			this->label58->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label58->ForeColor = System::Drawing::Color::Gainsboro;
			this->label58->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label58.Image")));
			this->label58->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label58->Location = System::Drawing::Point(3, 0);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(292, 48);
			this->label58->TabIndex = 16;
			this->label58->Text = L"Segmentation";
			this->label58->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label58->Click += gcnew System::EventHandler(this, &MyForm::label58_Click);
			// 
			// label59
			// 
			this->label59->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label59->ForeColor = System::Drawing::Color::Gainsboro;
			this->label59->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label59.Image")));
			this->label59->Location = System::Drawing::Point(3, 48);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(42, 44);
			this->label59->TabIndex = 21;
			this->label59->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel14
			// 
			this->panel14->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel14->Location = System::Drawing::Point(3, 354);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(317, 74);
			this->panel14->TabIndex = 11;
			// 
			// adjust
			// 
			this->adjust->Controls->Add(this->tit);
			this->adjust->Controls->Add(this->flowLayoutPanel6);
			this->adjust->Location = System::Drawing::Point(0, 0);
			this->adjust->Name = L"adjust";
			this->adjust->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->adjust->Size = System::Drawing::Size(308, 728);
			this->adjust->TabIndex = 2;
			this->adjust->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::adjust_Paint);
			// 
			// tit
			// 
			this->tit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->tit->Controls->Add(this->ti);
			this->tit->Controls->Add(this->button7);
			this->tit->Location = System::Drawing::Point(0, 0);
			this->tit->Name = L"tit";
			this->tit->Padding = System::Windows::Forms::Padding(10, 12, 10, 10);
			this->tit->Size = System::Drawing::Size(314, 47);
			this->tit->TabIndex = 5;
			// 
			// ti
			// 
			this->ti->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ti->ForeColor = System::Drawing::Color::Gainsboro;
			this->ti->Location = System::Drawing::Point(51, 0);
			this->ti->Name = L"ti";
			this->ti->Size = System::Drawing::Size(186, 44);
			this->ti->TabIndex = 8;
			this->ti->Text = L"Adjust";
			this->ti->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button7
			// 
			this->button7->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.BackgroundImage")));
			this->button7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Location = System::Drawing::Point(269, 6);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(20, 30);
			this->button7->TabIndex = 8;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// flowLayoutPanel6
			// 
			this->flowLayoutPanel6->Controls->Add(this->Auto);
			this->flowLayoutPanel6->Controls->Add(this->br);
			this->flowLayoutPanel6->Controls->Add(this->con);
			this->flowLayoutPanel6->Controls->Add(this->hig);
			this->flowLayoutPanel6->Controls->Add(this->ex);
			this->flowLayoutPanel6->Controls->Add(this->s);
			this->flowLayoutPanel6->Controls->Add(this->bw);
			this->flowLayoutPanel6->Location = System::Drawing::Point(16, 53);
			this->flowLayoutPanel6->Name = L"flowLayoutPanel6";
			this->flowLayoutPanel6->Size = System::Drawing::Size(321, 675);
			this->flowLayoutPanel6->TabIndex = 9;
			this->flowLayoutPanel6->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel6_Paint);
			// 
			// Auto
			// 
			this->Auto->Controls->Add(this->adjauto);
			this->Auto->Controls->Add(this->label5);
			this->Auto->Dock = System::Windows::Forms::DockStyle::Top;
			this->Auto->Location = System::Drawing::Point(3, 3);
			this->Auto->Name = L"Auto";
			this->Auto->Size = System::Drawing::Size(299, 74);
			this->Auto->TabIndex = 9;
			// 
			// adjauto
			// 
			this->adjauto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->adjauto->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"adjauto.BackgroundImage")));
			this->adjauto->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->adjauto->Cursor = System::Windows::Forms::Cursors::Hand;
			this->adjauto->FlatAppearance->BorderColor = System::Drawing::SystemColors::MenuHighlight;
			this->adjauto->FlatAppearance->BorderSize = 2;
			this->adjauto->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->adjauto->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->adjauto->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->adjauto->Location = System::Drawing::Point(168, 11);
			this->adjauto->Name = L"adjauto";
			this->adjauto->Size = System::Drawing::Size(95, 62);
			this->adjauto->TabIndex = 15;
			this->adjauto->UseVisualStyleBackColor = false;
			this->adjauto->Click += gcnew System::EventHandler(this, &MyForm::adjauto_Click);
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Gainsboro;
			this->label5->Location = System::Drawing::Point(-3, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(298, 74);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Auto";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// br
			// 
			this->br->Controls->Add(this->flowLayoutPanel8);
			this->br->Dock = System::Windows::Forms::DockStyle::Top;
			this->br->Location = System::Drawing::Point(3, 83);
			this->br->Name = L"br";
			this->br->Size = System::Drawing::Size(317, 74);
			this->br->TabIndex = 10;
			// 
			// flowLayoutPanel8
			// 
			this->flowLayoutPanel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel8->Controls->Add(this->bright);
			this->flowLayoutPanel8->Controls->Add(this->trackBar1);
			this->flowLayoutPanel8->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel8->Name = L"flowLayoutPanel8";
			this->flowLayoutPanel8->Size = System::Drawing::Size(299, 83);
			this->flowLayoutPanel8->TabIndex = 8;
			// 
			// bright
			// 
			this->bright->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->bright->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bright->ForeColor = System::Drawing::Color::Gainsboro;
			this->bright->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bright.Image")));
			this->bright->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->bright->Location = System::Drawing::Point(3, 0);
			this->bright->Name = L"bright";
			this->bright->Size = System::Drawing::Size(269, 40);
			this->bright->TabIndex = 15;
			this->bright->Text = L"Brightness";
			this->bright->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->bright->Click += gcnew System::EventHandler(this, &MyForm::bright_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->AutoSize = false;
			this->trackBar1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar1->Location = System::Drawing::Point(3, 43);
			this->trackBar1->Maximum = 129;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(270, 30);
			this->trackBar1->TabIndex = 8;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar1->Value = 64;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// con
			// 
			this->con->Controls->Add(this->flowLayoutPanel9);
			this->con->Dock = System::Windows::Forms::DockStyle::Top;
			this->con->Location = System::Drawing::Point(3, 163);
			this->con->Name = L"con";
			this->con->Size = System::Drawing::Size(317, 74);
			this->con->TabIndex = 11;
			// 
			// flowLayoutPanel9
			// 
			this->flowLayoutPanel9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel9->Controls->Add(this->label9);
			this->flowLayoutPanel9->Controls->Add(this->trackBar2);
			this->flowLayoutPanel9->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel9->Name = L"flowLayoutPanel9";
			this->flowLayoutPanel9->Size = System::Drawing::Size(299, 74);
			this->flowLayoutPanel9->TabIndex = 8;
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Gainsboro;
			this->label9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label9.Image")));
			this->label9->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label9->Location = System::Drawing::Point(3, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(260, 44);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Contrast";
			this->label9->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// trackBar2
			// 
			this->trackBar2->AutoSize = false;
			this->trackBar2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar2->Location = System::Drawing::Point(3, 47);
			this->trackBar2->Maximum = 15;
			this->trackBar2->Minimum = 1;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(270, 30);
			this->trackBar2->TabIndex = 17;
			this->trackBar2->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar2->Value = 1;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// hig
			// 
			this->hig->Controls->Add(this->flowLayoutPanel10);
			this->hig->Dock = System::Windows::Forms::DockStyle::Top;
			this->hig->Location = System::Drawing::Point(3, 243);
			this->hig->Name = L"hig";
			this->hig->Size = System::Drawing::Size(317, 74);
			this->hig->TabIndex = 13;
			// 
			// flowLayoutPanel10
			// 
			this->flowLayoutPanel10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel10->Controls->Add(this->label6);
			this->flowLayoutPanel10->Controls->Add(this->trackBar4);
			this->flowLayoutPanel10->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel10->Name = L"flowLayoutPanel10";
			this->flowLayoutPanel10->Size = System::Drawing::Size(299, 74);
			this->flowLayoutPanel10->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Gainsboro;
			this->label6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label6.Image")));
			this->label6->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label6->Location = System::Drawing::Point(3, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(299, 44);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Highlights";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar4
			// 
			this->trackBar4->AutoSize = false;
			this->trackBar4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar4->Location = System::Drawing::Point(3, 47);
			this->trackBar4->Maximum = 20;
			this->trackBar4->Minimum = 1;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(270, 30);
			this->trackBar4->TabIndex = 17;
			this->trackBar4->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar4->Value = 1;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar4_Scroll);
			// 
			// ex
			// 
			this->ex->Controls->Add(this->flowLayoutPanel7);
			this->ex->Dock = System::Windows::Forms::DockStyle::Top;
			this->ex->Location = System::Drawing::Point(3, 323);
			this->ex->Name = L"ex";
			this->ex->Size = System::Drawing::Size(317, 74);
			this->ex->TabIndex = 12;
			// 
			// flowLayoutPanel7
			// 
			this->flowLayoutPanel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel7->Controls->Add(this->label4);
			this->flowLayoutPanel7->Controls->Add(this->trackBar3);
			this->flowLayoutPanel7->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel7->Name = L"flowLayoutPanel7";
			this->flowLayoutPanel7->Size = System::Drawing::Size(299, 74);
			this->flowLayoutPanel7->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Gainsboro;
			this->label4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label4.Image")));
			this->label4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label4->Location = System::Drawing::Point(3, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(272, 44);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Exposure";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// trackBar3
			// 
			this->trackBar3->AutoSize = false;
			this->trackBar3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar3->Location = System::Drawing::Point(3, 47);
			this->trackBar3->Maximum = 255;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(270, 30);
			this->trackBar3->TabIndex = 17;
			this->trackBar3->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar3->Value = 1;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar3_Scroll);
			// 
			// s
			// 
			this->s->Controls->Add(this->flowLayoutPanel11);
			this->s->Dock = System::Windows::Forms::DockStyle::Top;
			this->s->Location = System::Drawing::Point(3, 403);
			this->s->Name = L"s";
			this->s->Size = System::Drawing::Size(317, 74);
			this->s->TabIndex = 14;
			// 
			// flowLayoutPanel11
			// 
			this->flowLayoutPanel11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel11->Controls->Add(this->label7);
			this->flowLayoutPanel11->Controls->Add(this->trackBar5);
			this->flowLayoutPanel11->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel11->Name = L"flowLayoutPanel11";
			this->flowLayoutPanel11->Size = System::Drawing::Size(299, 71);
			this->flowLayoutPanel11->TabIndex = 8;
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Gainsboro;
			this->label7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label7.Image")));
			this->label7->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label7->Location = System::Drawing::Point(3, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(272, 44);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Shadows";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar5
			// 
			this->trackBar5->AutoSize = false;
			this->trackBar5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar5->Location = System::Drawing::Point(3, 47);
			this->trackBar5->Maximum = 256;
			this->trackBar5->Minimum = 1;
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(270, 30);
			this->trackBar5->TabIndex = 17;
			this->trackBar5->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar5->Value = 1;
			this->trackBar5->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar5_Scroll);
			// 
			// bw
			// 
			this->bw->Controls->Add(this->flowLayoutPanel15);
			this->bw->Dock = System::Windows::Forms::DockStyle::Top;
			this->bw->Location = System::Drawing::Point(3, 483);
			this->bw->Name = L"bw";
			this->bw->Size = System::Drawing::Size(317, 121);
			this->bw->TabIndex = 15;
			// 
			// flowLayoutPanel15
			// 
			this->flowLayoutPanel15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel15->Controls->Add(this->label19);
			this->flowLayoutPanel15->Controls->Add(this->button18);
			this->flowLayoutPanel15->Controls->Add(this->button3);
			this->flowLayoutPanel15->Controls->Add(this->trackBar29);
			this->flowLayoutPanel15->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel15->Name = L"flowLayoutPanel15";
			this->flowLayoutPanel15->Size = System::Drawing::Size(299, 121);
			this->flowLayoutPanel15->TabIndex = 8;
			// 
			// label19
			// 
			this->label19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->label19->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::Gainsboro;
			this->label19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label19.Image")));
			this->label19->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label19->Location = System::Drawing::Point(3, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(293, 44);
			this->label19->TabIndex = 16;
			this->label19->Text = L"White To Black";
			this->label19->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label19->Click += gcnew System::EventHandler(this, &MyForm::label19_Click);
			// 
			// trackBar29
			// 
			this->trackBar29->AutoSize = false;
			this->trackBar29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar29->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar29->Location = System::Drawing::Point(3, 86);
			this->trackBar29->Maximum = 20;
			this->trackBar29->Minimum = 1;
			this->trackBar29->Name = L"trackBar29";
			this->trackBar29->Size = System::Drawing::Size(270, 30);
			this->trackBar29->TabIndex = 18;
			this->trackBar29->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar29->Value = 1;
			this->trackBar29->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar29_Scroll);
			// 
			// liquify
			// 
			this->liquify->Controls->Add(this->panel13);
			this->liquify->Controls->Add(this->flowLayoutPanel35);
			this->liquify->Location = System::Drawing::Point(0, 0);
			this->liquify->Name = L"liquify";
			this->liquify->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->liquify->Size = System::Drawing::Size(308, 728);
			this->liquify->TabIndex = 7;
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->panel13->Controls->Add(this->label62);
			this->panel13->Controls->Add(this->button10);
			this->panel13->Location = System::Drawing::Point(0, 0);
			this->panel13->Name = L"panel13";
			this->panel13->Padding = System::Windows::Forms::Padding(10, 12, 10, 10);
			this->panel13->Size = System::Drawing::Size(314, 47);
			this->panel13->TabIndex = 5;
			// 
			// label62
			// 
			this->label62->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label62->ForeColor = System::Drawing::Color::Gainsboro;
			this->label62->Location = System::Drawing::Point(51, 0);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(186, 44);
			this->label62->TabIndex = 8;
			this->label62->Text = L"Liquify";
			this->label62->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label62->Click += gcnew System::EventHandler(this, &MyForm::label62_Click);
			// 
			// button10
			// 
			this->button10->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button10.BackgroundImage")));
			this->button10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button10->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Location = System::Drawing::Point(269, 6);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(20, 30);
			this->button10->TabIndex = 8;
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click_1);
			// 
			// flowLayoutPanel35
			// 
			this->flowLayoutPanel35->Controls->Add(this->panel15);
			this->flowLayoutPanel35->Controls->Add(this->panel16);
			this->flowLayoutPanel35->Controls->Add(this->panel17);
			this->flowLayoutPanel35->Location = System::Drawing::Point(16, 53);
			this->flowLayoutPanel35->Name = L"flowLayoutPanel35";
			this->flowLayoutPanel35->Size = System::Drawing::Size(321, 675);
			this->flowLayoutPanel35->TabIndex = 9;
			// 
			// panel15
			// 
			this->panel15->Controls->Add(this->flowLayoutPanel36);
			this->panel15->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel15->Location = System::Drawing::Point(3, 3);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(317, 95);
			this->panel15->TabIndex = 13;
			// 
			// flowLayoutPanel36
			// 
			this->flowLayoutPanel36->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel36->Controls->Add(this->label63);
			this->flowLayoutPanel36->Controls->Add(this->trackBar28);
			this->flowLayoutPanel36->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel36->Name = L"flowLayoutPanel36";
			this->flowLayoutPanel36->Size = System::Drawing::Size(299, 91);
			this->flowLayoutPanel36->TabIndex = 8;
			this->flowLayoutPanel36->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel36_Paint);
			// 
			// label63
			// 
			this->label63->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label63->ForeColor = System::Drawing::Color::Gainsboro;
			this->label63->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label63.Image")));
			this->label63->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label63->Location = System::Drawing::Point(3, 0);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(292, 48);
			this->label63->TabIndex = 17;
			this->label63->Text = L"Layer";
			this->label63->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar28
			// 
			this->trackBar28->AutoSize = false;
			this->trackBar28->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar28->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar28->Location = System::Drawing::Point(3, 51);
			this->trackBar28->Maximum = 7;
			this->trackBar28->Name = L"trackBar28";
			this->trackBar28->Size = System::Drawing::Size(234, 25);
			this->trackBar28->TabIndex = 18;
			this->trackBar28->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar28->Value = 1;
			this->trackBar28->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar28_Scroll);
			// 
			// panel16
			// 
			this->panel16->Controls->Add(this->flowLayoutPanel37);
			this->panel16->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel16->Location = System::Drawing::Point(3, 104);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(317, 100);
			this->panel16->TabIndex = 14;
			// 
			// flowLayoutPanel37
			// 
			this->flowLayoutPanel37->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel37->Controls->Add(this->label64);
			this->flowLayoutPanel37->Controls->Add(this->trackBar26);
			this->flowLayoutPanel37->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel37->Name = L"flowLayoutPanel37";
			this->flowLayoutPanel37->Size = System::Drawing::Size(299, 93);
			this->flowLayoutPanel37->TabIndex = 8;
			// 
			// label64
			// 
			this->label64->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label64->ForeColor = System::Drawing::Color::Gainsboro;
			this->label64->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label64.Image")));
			this->label64->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label64->Location = System::Drawing::Point(3, 0);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(292, 48);
			this->label64->TabIndex = 16;
			this->label64->Text = L"compression";
			this->label64->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar26
			// 
			this->trackBar26->AutoSize = false;
			this->trackBar26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar26->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar26->Location = System::Drawing::Point(3, 51);
			this->trackBar26->Maximum = 100;
			this->trackBar26->Name = L"trackBar26";
			this->trackBar26->Size = System::Drawing::Size(234, 25);
			this->trackBar26->TabIndex = 17;
			this->trackBar26->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar26->Value = 1;
			this->trackBar26->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar26_Scroll);
			// 
			// panel17
			// 
			this->panel17->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel17->Location = System::Drawing::Point(3, 210);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(317, 74);
			this->panel17->TabIndex = 11;
			// 
			// filters
			// 
			this->filters->Controls->Add(this->panel5);
			this->filters->Controls->Add(this->flowLayoutPanel16);
			this->filters->Location = System::Drawing::Point(0, 0);
			this->filters->Name = L"filters";
			this->filters->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->filters->Size = System::Drawing::Size(308, 660);
			this->filters->TabIndex = 4;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->panel5->Controls->Add(this->label22);
			this->panel5->Controls->Add(this->button8);
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Padding = System::Windows::Forms::Padding(10, 12, 10, 10);
			this->panel5->Size = System::Drawing::Size(314, 47);
			this->panel5->TabIndex = 5;
			// 
			// label22
			// 
			this->label22->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::Color::Gainsboro;
			this->label22->Location = System::Drawing::Point(51, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(186, 44);
			this->label22->TabIndex = 8;
			this->label22->Text = L"Filters";
			this->label22->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button8
			// 
			this->button8->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.BackgroundImage")));
			this->button8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Location = System::Drawing::Point(269, 6);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(20, 30);
			this->button8->TabIndex = 8;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// flowLayoutPanel16
			// 
			this->flowLayoutPanel16->AutoScroll = true;
			this->flowLayoutPanel16->Controls->Add(this->sm);
			this->flowLayoutPanel16->Controls->Add(this->sh);
			this->flowLayoutPanel16->Controls->Add(this->grain);
			this->flowLayoutPanel16->Controls->Add(this->clr);
			this->flowLayoutPanel16->Controls->Add(this->blr);
			this->flowLayoutPanel16->Location = System::Drawing::Point(16, 53);
			this->flowLayoutPanel16->Name = L"flowLayoutPanel16";
			this->flowLayoutPanel16->Size = System::Drawing::Size(317, 630);
			this->flowLayoutPanel16->TabIndex = 9;
			// 
			// sm
			// 
			this->sm->Controls->Add(this->flowLayoutPanel18);
			this->sm->Dock = System::Windows::Forms::DockStyle::Top;
			this->sm->Location = System::Drawing::Point(3, 3);
			this->sm->Name = L"sm";
			this->sm->Size = System::Drawing::Size(317, 74);
			this->sm->TabIndex = 11;
			// 
			// flowLayoutPanel18
			// 
			this->flowLayoutPanel18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel18->Controls->Add(this->label25);
			this->flowLayoutPanel18->Controls->Add(this->trackBar14);
			this->flowLayoutPanel18->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel18->Name = L"flowLayoutPanel18";
			this->flowLayoutPanel18->Size = System::Drawing::Size(299, 74);
			this->flowLayoutPanel18->TabIndex = 8;
			// 
			// label25
			// 
			this->label25->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::Color::Gainsboro;
			this->label25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label25.Image")));
			this->label25->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label25->Location = System::Drawing::Point(3, 0);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(260, 44);
			this->label25->TabIndex = 16;
			this->label25->Text = L"Smooth";
			this->label25->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// trackBar14
			// 
			this->trackBar14->AutoSize = false;
			this->trackBar14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar14->Location = System::Drawing::Point(3, 47);
			this->trackBar14->Maximum = 255;
			this->trackBar14->Name = L"trackBar14";
			this->trackBar14->Size = System::Drawing::Size(256, 25);
			this->trackBar14->TabIndex = 17;
			this->trackBar14->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar14->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar14_Scroll);
			// 
			// sh
			// 
			this->sh->Controls->Add(this->flowLayoutPanel17);
			this->sh->Dock = System::Windows::Forms::DockStyle::Top;
			this->sh->Location = System::Drawing::Point(3, 83);
			this->sh->Name = L"sh";
			this->sh->Size = System::Drawing::Size(317, 111);
			this->sh->TabIndex = 10;
			// 
			// flowLayoutPanel17
			// 
			this->flowLayoutPanel17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel17->Controls->Add(this->label24);
			this->flowLayoutPanel17->Controls->Add(this->label67);
			this->flowLayoutPanel17->Controls->Add(this->trackBar27);
			this->flowLayoutPanel17->Controls->Add(this->label61);
			this->flowLayoutPanel17->Controls->Add(this->trackBar13);
			this->flowLayoutPanel17->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel17->Name = L"flowLayoutPanel17";
			this->flowLayoutPanel17->Size = System::Drawing::Size(299, 108);
			this->flowLayoutPanel17->TabIndex = 8;
			this->flowLayoutPanel17->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel17_Paint);
			// 
			// label24
			// 
			this->label24->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::Color::Gainsboro;
			this->label24->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label24.Image")));
			this->label24->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label24->Location = System::Drawing::Point(3, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(269, 40);
			this->label24->TabIndex = 15;
			this->label24->Text = L"Sharpen";
			this->label24->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label67
			// 
			this->label67->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label67->ForeColor = System::Drawing::Color::Gainsboro;
			this->label67->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label67.Image")));
			this->label67->Location = System::Drawing::Point(3, 40);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(42, 31);
			this->label67->TabIndex = 25;
			this->label67->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar27
			// 
			this->trackBar27->AutoSize = false;
			this->trackBar27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar27->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar27->Location = System::Drawing::Point(51, 43);
			this->trackBar27->Maximum = 255;
			this->trackBar27->Name = L"trackBar27";
			this->trackBar27->Size = System::Drawing::Size(234, 25);
			this->trackBar27->TabIndex = 16;
			this->trackBar27->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar27->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar27_Scroll);
			// 
			// label61
			// 
			this->label61->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label61->ForeColor = System::Drawing::Color::Gainsboro;
			this->label61->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label61.Image")));
			this->label61->Location = System::Drawing::Point(3, 71);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(42, 31);
			this->label61->TabIndex = 24;
			this->label61->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label61->Click += gcnew System::EventHandler(this, &MyForm::label61_Click);
			// 
			// trackBar13
			// 
			this->trackBar13->AutoSize = false;
			this->trackBar13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar13->Location = System::Drawing::Point(51, 74);
			this->trackBar13->Maximum = 255;
			this->trackBar13->Name = L"trackBar13";
			this->trackBar13->Size = System::Drawing::Size(234, 25);
			this->trackBar13->TabIndex = 8;
			this->trackBar13->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar13->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar13_Scroll);
			// 
			// grain
			// 
			this->grain->Controls->Add(this->flowLayoutPanel21);
			this->grain->Dock = System::Windows::Forms::DockStyle::Top;
			this->grain->Location = System::Drawing::Point(3, 200);
			this->grain->Name = L"grain";
			this->grain->Size = System::Drawing::Size(317, 171);
			this->grain->TabIndex = 14;
			// 
			// flowLayoutPanel21
			// 
			this->flowLayoutPanel21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel21->Controls->Add(this->label28);
			this->flowLayoutPanel21->Controls->Add(this->label50);
			this->flowLayoutPanel21->Controls->Add(this->trackBar17);
			this->flowLayoutPanel21->Controls->Add(this->label51);
			this->flowLayoutPanel21->Controls->Add(this->trackBar12);
			this->flowLayoutPanel21->Controls->Add(this->label52);
			this->flowLayoutPanel21->Controls->Add(this->trackBar20);
			this->flowLayoutPanel21->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel21->Name = L"flowLayoutPanel21";
			this->flowLayoutPanel21->Size = System::Drawing::Size(299, 168);
			this->flowLayoutPanel21->TabIndex = 8;
			this->flowLayoutPanel21->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel21_Paint);
			// 
			// label28
			// 
			this->label28->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->ForeColor = System::Drawing::Color::Gainsboro;
			this->label28->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label28.Image")));
			this->label28->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label28->Location = System::Drawing::Point(3, 0);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(253, 48);
			this->label28->TabIndex = 16;
			this->label28->Text = L"Grain";
			this->label28->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label28->Click += gcnew System::EventHandler(this, &MyForm::label28_Click);
			// 
			// label50
			// 
			this->label50->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label50->ForeColor = System::Drawing::Color::Gainsboro;
			this->label50->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label50.Image")));
			this->label50->Location = System::Drawing::Point(3, 48);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(42, 44);
			this->label50->TabIndex = 21;
			this->label50->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label50->Click += gcnew System::EventHandler(this, &MyForm::label50_Click);
			// 
			// trackBar17
			// 
			this->trackBar17->AutoSize = false;
			this->trackBar17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar17->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar17->Location = System::Drawing::Point(51, 51);
			this->trackBar17->Maximum = 100;
			this->trackBar17->Name = L"trackBar17";
			this->trackBar17->Size = System::Drawing::Size(234, 25);
			this->trackBar17->TabIndex = 17;
			this->trackBar17->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar17->Value = 1;
			this->trackBar17->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar17_Scroll);
			// 
			// label51
			// 
			this->label51->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label51->ForeColor = System::Drawing::Color::Gainsboro;
			this->label51->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label51.Image")));
			this->label51->Location = System::Drawing::Point(3, 92);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(42, 44);
			this->label51->TabIndex = 22;
			this->label51->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar12
			// 
			this->trackBar12->AutoSize = false;
			this->trackBar12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar12->Location = System::Drawing::Point(51, 95);
			this->trackBar12->Maximum = 100;
			this->trackBar12->Name = L"trackBar12";
			this->trackBar12->Size = System::Drawing::Size(234, 25);
			this->trackBar12->TabIndex = 18;
			this->trackBar12->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar12->Value = 1;
			this->trackBar12->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar12_Scroll);
			// 
			// label52
			// 
			this->label52->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label52->ForeColor = System::Drawing::Color::Gainsboro;
			this->label52->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label52.Image")));
			this->label52->Location = System::Drawing::Point(3, 136);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(42, 31);
			this->label52->TabIndex = 23;
			this->label52->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar20
			// 
			this->trackBar20->AutoSize = false;
			this->trackBar20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar20->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar20->Location = System::Drawing::Point(51, 139);
			this->trackBar20->Maximum = 100;
			this->trackBar20->Name = L"trackBar20";
			this->trackBar20->Size = System::Drawing::Size(234, 25);
			this->trackBar20->TabIndex = 19;
			this->trackBar20->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar20->Value = 1;
			this->trackBar20->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar20_Scroll);
			// 
			// clr
			// 
			this->clr->Controls->Add(this->flowLayoutPanel20);
			this->clr->Dock = System::Windows::Forms::DockStyle::Top;
			this->clr->Location = System::Drawing::Point(3, 377);
			this->clr->Name = L"clr";
			this->clr->Size = System::Drawing::Size(317, 85);
			this->clr->TabIndex = 13;
			// 
			// flowLayoutPanel20
			// 
			this->flowLayoutPanel20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel20->Controls->Add(this->label27);
			this->flowLayoutPanel20->Controls->Add(this->trackBar16);
			this->flowLayoutPanel20->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel20->Name = L"flowLayoutPanel20";
			this->flowLayoutPanel20->Size = System::Drawing::Size(299, 82);
			this->flowLayoutPanel20->TabIndex = 8;
			this->flowLayoutPanel20->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel20_Paint);
			// 
			// label27
			// 
			this->label27->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->ForeColor = System::Drawing::Color::Gainsboro;
			this->label27->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label27.Image")));
			this->label27->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label27->Location = System::Drawing::Point(3, 0);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(283, 44);
			this->label27->TabIndex = 16;
			this->label27->Text = L"Clarity";
			this->label27->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label27->Click += gcnew System::EventHandler(this, &MyForm::label27_Click);
			// 
			// trackBar16
			// 
			this->trackBar16->AutoSize = false;
			this->trackBar16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar16->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar16->Location = System::Drawing::Point(3, 47);
			this->trackBar16->Maximum = 255;
			this->trackBar16->Name = L"trackBar16";
			this->trackBar16->Size = System::Drawing::Size(256, 25);
			this->trackBar16->TabIndex = 17;
			this->trackBar16->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar16->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar16_Scroll);
			// 
			// blr
			// 
			this->blr->Controls->Add(this->flowLayoutPanel19);
			this->blr->Dock = System::Windows::Forms::DockStyle::Top;
			this->blr->Location = System::Drawing::Point(3, 468);
			this->blr->Name = L"blr";
			this->blr->Size = System::Drawing::Size(317, 191);
			this->blr->TabIndex = 12;
			// 
			// flowLayoutPanel19
			// 
			this->flowLayoutPanel19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel19->Controls->Add(this->label26);
			this->flowLayoutPanel19->Controls->Add(this->label68);
			this->flowLayoutPanel19->Controls->Add(this->trackBar21);
			this->flowLayoutPanel19->Controls->Add(this->label69);
			this->flowLayoutPanel19->Controls->Add(this->trackBar15);
			this->flowLayoutPanel19->Controls->Add(this->button23);
			this->flowLayoutPanel19->Controls->Add(this->button25);
			this->flowLayoutPanel19->Controls->Add(this->button24);
			this->flowLayoutPanel19->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel19->Name = L"flowLayoutPanel19";
			this->flowLayoutPanel19->Size = System::Drawing::Size(299, 188);
			this->flowLayoutPanel19->TabIndex = 8;
			this->flowLayoutPanel19->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel19_Paint);
			// 
			// label26
			// 
			this->label26->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::Color::Gainsboro;
			this->label26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label26.Image")));
			this->label26->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label26->Location = System::Drawing::Point(3, 0);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(253, 44);
			this->label26->TabIndex = 16;
			this->label26->Text = L"Blur";
			this->label26->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label26->Click += gcnew System::EventHandler(this, &MyForm::label26_Click);
			// 
			// label68
			// 
			this->label68->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->label68->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label68->ForeColor = System::Drawing::Color::Gainsboro;
			this->label68->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label68.Image")));
			this->label68->Location = System::Drawing::Point(3, 44);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(42, 44);
			this->label68->TabIndex = 23;
			this->label68->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label68->Click += gcnew System::EventHandler(this, &MyForm::label68_Click);
			// 
			// trackBar21
			// 
			this->trackBar21->AutoSize = false;
			this->trackBar21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar21->Location = System::Drawing::Point(51, 47);
			this->trackBar21->Maximum = 255;
			this->trackBar21->Name = L"trackBar21";
			this->trackBar21->Size = System::Drawing::Size(234, 25);
			this->trackBar21->TabIndex = 21;
			this->trackBar21->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar21->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar21_Scroll_2);
			// 
			// label69
			// 
			this->label69->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label69->ForeColor = System::Drawing::Color::Gainsboro;
			this->label69->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label69.Image")));
			this->label69->Location = System::Drawing::Point(3, 88);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(42, 44);
			this->label69->TabIndex = 24;
			this->label69->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar15
			// 
			this->trackBar15->AutoSize = false;
			this->trackBar15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar15->Location = System::Drawing::Point(51, 91);
			this->trackBar15->Maximum = 255;
			this->trackBar15->Name = L"trackBar15";
			this->trackBar15->Size = System::Drawing::Size(234, 25);
			this->trackBar15->TabIndex = 17;
			this->trackBar15->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar15->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar15_Scroll);
			// 
			// Effect
			// 
			this->Effect->Controls->Add(this->panel3);
			this->Effect->Controls->Add(this->flowLayoutPanel28);
			this->Effect->Location = System::Drawing::Point(0, 0);
			this->Effect->Name = L"Effect";
			this->Effect->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Effect->Size = System::Drawing::Size(308, 728);
			this->Effect->TabIndex = 5;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->panel3->Controls->Add(this->label53);
			this->panel3->Controls->Add(this->button27);
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Padding = System::Windows::Forms::Padding(10, 12, 10, 10);
			this->panel3->Size = System::Drawing::Size(314, 47);
			this->panel3->TabIndex = 5;
			// 
			// label53
			// 
			this->label53->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label53->ForeColor = System::Drawing::Color::Gainsboro;
			this->label53->Location = System::Drawing::Point(51, 0);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(186, 44);
			this->label53->TabIndex = 8;
			this->label53->Text = L"Effect";
			this->label53->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button27
			// 
			this->button27->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button27->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button27.BackgroundImage")));
			this->button27->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button27->FlatAppearance->BorderSize = 0;
			this->button27->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DodgerBlue;
			this->button27->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DodgerBlue;
			this->button27->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button27->Location = System::Drawing::Point(269, 6);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(20, 30);
			this->button27->TabIndex = 8;
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
			// 
			// flowLayoutPanel28
			// 
			this->flowLayoutPanel28->Controls->Add(this->panel7);
			this->flowLayoutPanel28->Controls->Add(this->panel8);
			this->flowLayoutPanel28->Controls->Add(this->panel9);
			this->flowLayoutPanel28->Controls->Add(this->panel10);
			this->flowLayoutPanel28->Location = System::Drawing::Point(16, 53);
			this->flowLayoutPanel28->Name = L"flowLayoutPanel28";
			this->flowLayoutPanel28->Size = System::Drawing::Size(321, 675);
			this->flowLayoutPanel28->TabIndex = 9;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->flowLayoutPanel29);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel7->Location = System::Drawing::Point(3, 3);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(317, 74);
			this->panel7->TabIndex = 13;
			// 
			// flowLayoutPanel29
			// 
			this->flowLayoutPanel29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel29->Controls->Add(this->button31);
			this->flowLayoutPanel29->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel29->Name = L"flowLayoutPanel29";
			this->flowLayoutPanel29->Size = System::Drawing::Size(299, 74);
			this->flowLayoutPanel29->TabIndex = 8;
			// 
			// button31
			// 
			this->button31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->button31->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button31->FlatAppearance->BorderSize = 0;
			this->button31->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button31->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button31->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button31->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold));
			this->button31->ForeColor = System::Drawing::Color::Gainsboro;
			this->button31->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button31.Image")));
			this->button31->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button31->Location = System::Drawing::Point(3, 3);
			this->button31->Name = L"button31";
			this->button31->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->button31->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button31->Size = System::Drawing::Size(282, 66);
			this->button31->TabIndex = 17;
			this->button31->Text = L"Invert ";
			this->button31->UseVisualStyleBackColor = false;
			this->button31->Click += gcnew System::EventHandler(this, &MyForm::button31_Click_1);
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->flowLayoutPanel30);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel8->Location = System::Drawing::Point(3, 83);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(317, 138);
			this->panel8->TabIndex = 14;
			this->panel8->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel8_Paint);
			// 
			// flowLayoutPanel30
			// 
			this->flowLayoutPanel30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel30->Controls->Add(this->label55);
			this->flowLayoutPanel30->Controls->Add(this->label56);
			this->flowLayoutPanel30->Controls->Add(this->trackBar22);
			this->flowLayoutPanel30->Controls->Add(this->label57);
			this->flowLayoutPanel30->Controls->Add(this->trackBar23);
			this->flowLayoutPanel30->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel30->Name = L"flowLayoutPanel30";
			this->flowLayoutPanel30->Size = System::Drawing::Size(299, 135);
			this->flowLayoutPanel30->TabIndex = 8;
			// 
			// label55
			// 
			this->label55->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->label55->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label55->ForeColor = System::Drawing::Color::Gainsboro;
			this->label55->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label55.Image")));
			this->label55->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label55->Location = System::Drawing::Point(3, 0);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(292, 48);
			this->label55->TabIndex = 16;
			this->label55->Text = L"Invert Selection";
			this->label55->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label56
			// 
			this->label56->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label56->ForeColor = System::Drawing::Color::Gainsboro;
			this->label56->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label56.Image")));
			this->label56->Location = System::Drawing::Point(3, 48);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(42, 44);
			this->label56->TabIndex = 21;
			this->label56->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar22
			// 
			this->trackBar22->AutoSize = false;
			this->trackBar22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar22->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar22->Location = System::Drawing::Point(51, 51);
			this->trackBar22->Maximum = 255;
			this->trackBar22->Name = L"trackBar22";
			this->trackBar22->Size = System::Drawing::Size(234, 25);
			this->trackBar22->TabIndex = 17;
			this->trackBar22->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackBar22->Value = 1;
			this->trackBar22->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar22_Scroll);
			// 
			// label57
			// 
			this->label57->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->label57->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label57->ForeColor = System::Drawing::Color::Gainsboro;
			this->label57->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label57.Image")));
			this->label57->Location = System::Drawing::Point(3, 92);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(42, 44);
			this->label57->TabIndex = 22;
			this->label57->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar23
			// 
			this->trackBar23->AutoSize = false;
			this->trackBar23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar23->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar23->Location = System::Drawing::Point(51, 95);
			this->trackBar23->Maximum = 255;
			this->trackBar23->Name = L"trackBar23";
			this->trackBar23->Size = System::Drawing::Size(234, 25);
			this->trackBar23->TabIndex = 18;
			this->trackBar23->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackBar23->Value = 1;
			this->trackBar23->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar23_Scroll);
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->flowLayoutPanel31);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel9->Location = System::Drawing::Point(3, 227);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(317, 115);
			this->panel9->TabIndex = 10;
			// 
			// flowLayoutPanel31
			// 
			this->flowLayoutPanel31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel31->Controls->Add(this->button28);
			this->flowLayoutPanel31->Controls->Add(this->trackBar25);
			this->flowLayoutPanel31->Location = System::Drawing::Point(0, 3);
			this->flowLayoutPanel31->Name = L"flowLayoutPanel31";
			this->flowLayoutPanel31->Size = System::Drawing::Size(299, 112);
			this->flowLayoutPanel31->TabIndex = 8;
			// 
			// button28
			// 
			this->button28->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button28->FlatAppearance->BorderSize = 0;
			this->button28->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button28->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button28->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button28->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.125F, System::Drawing::FontStyle::Bold));
			this->button28->ForeColor = System::Drawing::Color::Gainsboro;
			this->button28->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button28.Image")));
			this->button28->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button28->Location = System::Drawing::Point(3, 3);
			this->button28->Name = L"button28";
			this->button28->Padding = System::Windows::Forms::Padding(3, 6, 0, 3);
			this->button28->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button28->Size = System::Drawing::Size(286, 66);
			this->button28->TabIndex = 16;
			this->button28->Text = L"Blinding";
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
			// 
			// trackBar25
			// 
			this->trackBar25->AutoSize = false;
			this->trackBar25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->trackBar25->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar25->Location = System::Drawing::Point(3, 75);
			this->trackBar25->Maximum = 9;
			this->trackBar25->Minimum = 1;
			this->trackBar25->Name = L"trackBar25";
			this->trackBar25->Size = System::Drawing::Size(256, 25);
			this->trackBar25->TabIndex = 8;
			this->trackBar25->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackBar25->Value = 1;
			this->trackBar25->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar25_Scroll);
			// 
			// panel10
			// 
			this->panel10->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel10->Location = System::Drawing::Point(3, 348);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(317, 74);
			this->panel10->TabIndex = 11;
			// 
			// ofd
			// 
			this->ofd->FileName = L"openFileDialog1";
			this->ofd->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(24, 44);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->ClientSize = System::Drawing::Size(1448, 771);
			this->Controls->Add(this->center);
			this->Controls->Add(this->down);
			this->Controls->Add(this->manue);
			this->Controls->Add(this->top);
			this->Font = (gcnew System::Drawing::Font(L"Century", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			toolTip2->SetToolTip(this, L"-->PLEASE CLICK DONE <--\r\n -->TO SAVE THIS EDIT<--\r\n\r\n\r\n");
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar19))->EndInit();
			this->down->ResumeLayout(false);
			this->flowLayoutPanel22->ResumeLayout(false);
			this->flowLayoutPanel23->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar18))->EndInit();
			this->home->ResumeLayout(false);
			this->home->PerformLayout();
			this->dafter->ResumeLayout(false);
			this->flowLayoutPanel26->ResumeLayout(false);
			this->flowLayoutPanel26->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->dbefor->ResumeLayout(false);
			this->flowLayoutPanel27->ResumeLayout(false);
			this->flowLayoutPanel27->PerformLayout();
			this->panel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->befor->ResumeLayout(false);
			this->befor->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->title->ResumeLayout(false);
			this->Histogram->ResumeLayout(false);
			this->Histogram->PerformLayout();
			this->panel18->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->edit->ResumeLayout(false);
			this->T->ResumeLayout(false);
			this->flowLayoutPanel2->ResumeLayout(false);
			this->sk->ResumeLayout(false);
			this->flowLayoutPanel24->ResumeLayout(false);
			this->Rotate->ResumeLayout(false);
			this->flowLayoutPanel4->ResumeLayout(false);
			this->zoom->ResumeLayout(false);
			this->flowLayoutPanel14->ResumeLayout(false);
			this->clip->ResumeLayout(false);
			this->flowLayoutPanel12->ResumeLayout(false);
			this->resize->ResumeLayout(false);
			this->flowLayoutPanel13->ResumeLayout(false);
			this->flip->ResumeLayout(false);
			this->flowLayoutPanel5->ResumeLayout(false);
			this->top->ResumeLayout(false);
			this->manue->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->center->ResumeLayout(false);
			this->detect->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->flowLayoutPanel32->ResumeLayout(false);
			this->panel11->ResumeLayout(false);
			this->flowLayoutPanel33->ResumeLayout(false);
			this->flowLayoutPanel33->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->flowLayoutPanel34->ResumeLayout(false);
			this->adjust->ResumeLayout(false);
			this->tit->ResumeLayout(false);
			this->flowLayoutPanel6->ResumeLayout(false);
			this->Auto->ResumeLayout(false);
			this->br->ResumeLayout(false);
			this->flowLayoutPanel8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->con->ResumeLayout(false);
			this->flowLayoutPanel9->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->hig->ResumeLayout(false);
			this->flowLayoutPanel10->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			this->ex->ResumeLayout(false);
			this->flowLayoutPanel7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->s->ResumeLayout(false);
			this->flowLayoutPanel11->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->EndInit();
			this->bw->ResumeLayout(false);
			this->flowLayoutPanel15->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar29))->EndInit();
			this->liquify->ResumeLayout(false);
			this->panel13->ResumeLayout(false);
			this->flowLayoutPanel35->ResumeLayout(false);
			this->panel15->ResumeLayout(false);
			this->flowLayoutPanel36->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar28))->EndInit();
			this->panel16->ResumeLayout(false);
			this->flowLayoutPanel37->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar26))->EndInit();
			this->filters->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->flowLayoutPanel16->ResumeLayout(false);
			this->sm->ResumeLayout(false);
			this->flowLayoutPanel18->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar14))->EndInit();
			this->sh->ResumeLayout(false);
			this->flowLayoutPanel17->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar13))->EndInit();
			this->grain->ResumeLayout(false);
			this->flowLayoutPanel21->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar20))->EndInit();
			this->clr->ResumeLayout(false);
			this->flowLayoutPanel20->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar16))->EndInit();
			this->blr->ResumeLayout(false);
			this->flowLayoutPanel19->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar15))->EndInit();
			this->Effect->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->flowLayoutPanel28->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->flowLayoutPanel29->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->flowLayoutPanel30->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar23))->EndInit();
			this->panel9->ResumeLayout(false);
			this->flowLayoutPanel31->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar25))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Environment::Exit(0);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->WindowState = FormWindowState::Minimized;

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->WindowState == FormWindowState::Maximized) {
		this->WindowState = FormWindowState::Normal;

	}
	else
	{
		this->WindowState = FormWindowState::Maximized;

	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolTip1_Popup(System::Object^ sender, System::Windows::Forms::PopupEventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	adjust->BringToFront();
	if (adjust->Visible == false) {
		adjust->Visible = true;

	}
	if (done->Visible == false) {
		done->Visible = true;

	}


}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click_1(System::Object^ sender, System::EventArgs^ e) {
	filters->BringToFront();
	if (filters->Visible == false) {
		filters->Visible = true;

	}
	if (done->Visible == false) {
		done->Visible = true;

	}


}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	edit->BringToFront();
	if (edit->Visible == false) {
		edit->Visible = true;

	}
	if (done->Visible == false) {
		done->Visible = true;

	}

}
private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void Blu_Click(System::Object^ sender, System::EventArgs^ e) {
	Effect->BringToFront();
	if (Effect->Visible == false) {
		Effect->Visible = true;

	}
	if (done->Visible == false) {
		done->Visible = true;

	}


}
private: System::Void hom_Click(System::Object^ sender, System::EventArgs^ e) {

	home->BringToFront();
	if (done->Visible == true) {
		done->Visible = false;
	}

}
private: System::Void button1_Click_2(System::Object^ sender, System::EventArgs^ e) {
	if (manue->Width == 45) {
		manue->Width = 185

			;
	}
	else
	{
		manue->Width = 45;
	}
}
private: System::Void CTitle_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void flowLayoutPanel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cr_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

private: System::Void flip_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {
	//////////////flip////////////////////////////
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	cv::flip(src, dst, 0);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";
	src = dst.clone();


}
private: System::Void button6_Click_2(System::Object^ sender, System::EventArgs^ e) {
	if (edit->Visible == true) {
		edit->Visible = false;

	}
	if (done->Visible == true) {
		done->Visible = false;

	}
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void adjust_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if (adjust->Visible == true) {
		adjust->Visible = false;



	}

	if (done->Visible == true) {
		done->Visible = false;
	}
}

private: System::Void flowLayoutPanel6_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void adjauto_Click(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	equalizeHist(src, dst);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	//src = dst.clone();


}

private: System::Void trackBar11_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	int R = trackBar6->Value;
	int Z = trackBar11->Value;


	Mat RM;


	RM = getRotationMatrix2D(Point2f(src.cols / 2, src.rows / 2), R, Z / 100.0);// we make a rotation matrix using the values from the trackbars
	warpAffine(src, dst, RM, src.size());
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";
	//src = dst.clone();






}
private: System::Void label16_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void flowLayoutPanel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void down_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void flowLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

}
private: System::Void edit_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void flowLayoutPanel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label26_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label28_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	if (filters->Visible == true) {
		filters->Visible = false;

	}
	if (done->Visible == true) {
		done->Visible = false;
	}
}

private: System::Void flowLayoutPanel26_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label33_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ image = gcnew OpenFileDialog();//and show him a dialog box to pick it from anywhere on the pc
	image->Filter = "image Files|*.png;*.jpeg;*.jpg;*.jpe;*.jfif;*.webp";//we give it some filters to pick nly image types
	if (image->ShowDialog() != System::Windows::Forms::DialogResult::OK)//if the user doesn't pick an image it will stop the function and return without contienuing
	{
		return;
	}

	sour->Text = image->FileName;//and write the path of the image on the label under the button
	pictureBox1->ImageLocation = image->FileName;//then load the source image in the first picture box to show what we are dealing with
	MarshalString(image->FileName, locdirc);//and save the location in the locdirc variable we made
	src = imread(locdirc, 0);//and here we read the source and dst variables to use them in any ork we want
	dst = imread(locdirc, 0);
	cv::imwrite(testdirc, src);//and we work on a copy we will make in the project directory to avoid any unwanted changes to the main image
	pictureBox2->ImageLocation = "test.jpeg";
	tpb->Text = src.total().ToString();
	hb->Text = src.rows.ToString();
	wb->Text = src.cols.ToString();
	cb->Text = src.channels().ToString();
	db->Text = src.depth().ToString();
	infob->Text = src.rows.ToString()+"X"+ src.cols.ToString()+"px";



	int max = 0;
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			if (src.at<uchar>(i, j) > max)
				max = src.at<uchar>(i, j);
		}
	}
	maxcb->Text = max.ToString();

	int min = 0;
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			if (src.at<uchar>(i, j) < min)
				min = src.at<uchar>(i, j);
		}
	}

	mcb->Text = min.ToString();


	int sum = 0;//we get the sum of ampitude values in a grey scale of the image
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			sum = sum + src.at<uchar>(i, j);

	int avg = sum / src.total();//and get the average of it

	acb->Text = avg.ToString();
	for (int amp = 0; amp < 256; amp++) {
		for (int i = 0; i < src.rows; i++) {

			for (int j = 0; j < src.cols; j++) {

				if (src.at<uchar>(i, j) == amp)
				{
					hist[amp] = hist[amp] + 1;

				}
			}

		}
		if (hist[amp] != 0)
		{
			histogramtextBox->Text = hist[amp].ToString();
		}
	}

	
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void befor_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}


private: System::Void flowLayoutPanel23_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	SaveFileDialog^ image = gcnew SaveFileDialog();//instead of the openfile box we used to get an image we use a savefile box as it can or cannot be something to overwrite
	image->Filter = "image Files|*.png;*.jpeg;*.jpg;*.jpe;*.jfif;*.webp";
	if (image->ShowDialog() != System::Windows::Forms::DialogResult::OK)
	{
		return;
	}
	MarshalString(image->FileName, savedirc);
	dst = cv::imread(testdirc);
	cv::imwrite(savedirc, dst);

}
private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	///////rotateleft/////////
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	src = dst.clone();

	Mat RM = getRotationMatrix2D(Point2f(src.cols / 2, src.rows / 2), -90, 1);
	warpAffine(src, dst, RM, src.size());
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;

}
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
	//////////////flip////////////////////////////
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	cv::flip(src, dst, 1);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	src = dst.clone();
}
private: System::Void trackBar7_Scroll(System::Object^ sender, System::EventArgs^ e) {
if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	trackBar7->Minimum = src.cols;

	trackBar7->Maximum =2 * src.cols;
	trackBar10->Minimum = src.rows;

	trackBar10->Maximum = 2 * src.rows;

	int Tc = trackBar7->Value;
	int Tr = trackBar10->Value;

	int tx = Tc - src.cols;
	int ty = Tr - src.rows;
	Mat TM = (Mat_<float>(2, 3) << 1, 0, tx, 0, 1, ty);// a matrix to use for the warm affine function 
	warpAffine(src, dst, TM, src.size());
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";



}
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
	///////rotateright/////////
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	src = src.clone();

	Mat RM = getRotationMatrix2D(Point2f(src.cols / 2, src.rows / 2), 90, 1);
	warpAffine(src, dst, RM, src.size());
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
}
private: System::Void trackBar18_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	dst = src.clone();

	int R = trackBar6->Value;
	int Z = trackBar11->Value;
	int Zm=	trackBar18->Value;
	Z = Zm;

	dst = src.clone();

	Mat RM;


	RM = getRotationMatrix2D(Point2f(src.cols / 2, src.rows / 2), R, Z / 100.0);// we make a rotation matrix using the values from the trackbars
	warpAffine(src, dst, RM, src.size());
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";




}
private: System::Void right_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar6_Scroll(System::Object^ sender, System::EventArgs^ e) {

	
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}	
	int R = trackBar6->Value;
	int Z = trackBar11->Value;

 
		Mat RM;


		RM = getRotationMatrix2D(Point2f(src.cols / 2, src.rows / 2), R, Z / 100.0);// we make a rotation matrix using the values from the trackbars
		warpAffine(src, dst, RM, src.size());
		imwrite("test.jpg", dst);
				pictureBox2->ImageLocation = "test.jpg";
				ofd->FileName = pictureBox2->ImageLocation;
				infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";

	//src = dst.clone();

		


}
private: System::Void trackBar19_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	Point2f src_p[3];
	src_p[0] = Point2f(0, 0);
	src_p[1] = Point2f(src.cols - 1, 0);
	src_p[2] = Point2f(0, src.rows - 1);
	Point2f dst_p[3];
	dst_p[0] = Point2f(0, 0);
	dst_p[1] = Point2f(src.cols - 1, 0);
	dst_p[2] = Point2f(trackBar19->Value, src.rows - 1);

	Mat SM = getAffineTransform(src_p, dst_p);
	warpAffine(src, dst, SM, src.size());
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";

}
private: System::Void trackBar10_Scroll(System::Object^ sender, System::EventArgs^ e) {
if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	trackBar7->Minimum = src.cols;

	trackBar7->Maximum = 2 * src.cols;
	trackBar10->Minimum = src.rows;

	trackBar10->Maximum = 2 * src.rows;

	int Tc = trackBar7->Value;
	int Tr = trackBar10->Value;

	int tx = Tc - src.cols;
	int ty = Tr - src.rows;
	Mat TM = (Mat_<float>(2, 3) << 1, 0, tx, 0, 1, ty);// a matrix to use for the warm affine function 
	warpAffine(src, dst, TM, src.size());
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";

	
}
private: System::Void trackBar8_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}


	int dx = trackBar8->Value;
	int dy = trackBar9->Value;


	cv::resize(src, dst, cv::Size(), dx / 100.0, dy / 100.0, INTER_CUBIC);// we use the inter cubic method of scaling as it's the more stable one for both scaling up and down
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";

}
private: System::Void trackBar9_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}


	int dx = trackBar8->Value;
	int dy = trackBar9->Value;


	cv::resize(src, dst, cv::Size(), dx / 100.0, dy / 100.0, INTER_CUBIC);// we use the inter cubic method of scaling as it's the more stable one for both scaling up and down
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";

}
private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
//pow alpha>1	
	int C = trackBar2->Value;
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	dst = Mat(src.size(), CV_32FC1, Scalar(0));
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			dst.at<float>(i, j) = powf(src.at<uchar>(i, j) + 1, C);
	normalize(dst, dst, 0, 255, NORM_MINMAX);
	convertScaleAbs(dst, dst);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;


}
private: System::Void trackBar4_Scroll(System::Object^ sender, System::EventArgs^ e) {
//power alpha<1
	int H = trackBar4->Value;
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	dst = Mat(src.size(), CV_32FC1, Scalar(0));
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			dst.at<float>(i, j) = powf(src.at<uchar>(i, j) + 1, H*0.1);
	normalize(dst, dst, 0, 255, NORM_MINMAX);
	convertScaleAbs(dst, dst);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;

}
private: System::Void trackBar5_Scroll(System::Object^ sender, System::EventArgs^ e) {
//mean noise
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	RNG rng;

	int sp = trackBar20->Value;
	int sh = trackBar5->Value;
	rng.fill(dst, RNG::NORMAL, sh, sp);
	add(src, dst, dst);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";
	
	
	
	
}
private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e) {


//log
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	int L = trackBar3->Value;
	
	dst = Mat(src.size(), CV_32FC1, Scalar(0));
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			dst.at<float>(i, j) = cv::log(src.at<uchar>(i, j) + L);
	normalize(dst, dst, 0, 255, NORM_MINMAX);
	convertScaleAbs(dst, dst);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation; 

}
private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int b = trackBar1->Value;
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	//log inv

	dst = Mat(src.size(), CV_32FC1, Scalar(0));
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			dst.at<float>(i, j) = powf(src.at<uchar>(i, j) + 1, b * 0.1);
	normalize(dst, dst, 0, 255, NORM_MINMAX);
	convertScaleAbs(dst, dst);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;


}


private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button18_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	dst = Mat(src.size(), CV_8UC1, Scalar(0));
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			dst.at<uchar>(i, j) = src.at<uchar>(i, j) + 10;
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
}
private: System::Void button3_Click_2(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	dst = Mat(src.size(), CV_8UC1, Scalar(0));
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			dst.at<uchar>(i, j) = src.at<uchar>(i, j) -10;
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
}

private: System::Void label19_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	pictureBox1->ImageLocation = "";
	pictureBox2->ImageLocation = "";

	pictureBox2->Text = "";
	pictureBox1->Text = "";
	sour->Text = "";
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Restart();

}
private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
	if (befor->Visible == true) {
		befor->Visible = false;



	}
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	if (befor->Visible == false) {
		befor->Visible = true;

	}
}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void flowLayoutPanel26_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void flowLayoutPanel26_Paint_2(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label35_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label34_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel4_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dafter->Visible == true) {
		dafter->Visible = false;



	}
}
private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dbefor->Visible == true) {
		dbefor->Visible = false;



	}
}
private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (dbefor->Visible == false) {
		dbefor->Visible = true;



	}

}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dafter->Visible == false) {
		dafter->Visible = true;
		if (done->Visible == true) {
			done->Visible = false;
		}

		if (src.empty()) {
			MessageBox::Show("no image ");
			return;
		}
		tpa->Text = dst.total().ToString();
		ha->Text = dst.rows.ToString();
		wa->Text = dst.cols.ToString();
		ca->Text = dst.channels().ToString();
	da->Text = dst.depth().ToString();


		int max = 0;
		for (int i = 0; i < dst.rows; i++) {
			for (int j = 0; j < dst.cols; j++) {
				if (dst.at<uchar>(i, j) > max)
					max = dst.at<uchar>(i, j);
			}
		}
		maxca->Text = max.ToString();

		int min = 0;
		for (int i = 0; i < dst.rows; i++) {
			for (int j = 0; j < dst.cols; j++) {
				if (dst.at<uchar>(i, j) < min)
					min = dst.at<uchar>(i, j);
			}
		}

		Mca->Text = min.ToString();


		int sum = 0;//we get the sum of ampitude values in a grey scale of the image
		for (int i = 0; i < dst.rows; i++)
			for (int j = 0; j < dst.cols; j++)
				sum = sum + dst.at<uchar>(i, j);

		int avg = sum / dst.total();//and get the average of it

		Aca->Text = avg.ToString();


	}

}
private: System::Void textBox1_TextChanged_2(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void infob_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void infoa_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	

}
private: System::Void flowLayoutPanel19_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
	///////circular filter////////
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	Mat kernal_c = (Mat_<float>(5, 5) << 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0);
	kernal_c = kernal_c / 21;
	//rect 
	filter2D(src, dst, CV_8UC1, kernal_c);


	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	src = dst.clone();


}
private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
	///////pyramidal fliter//////////

	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	Mat kernal_p = (Mat_<float>(5, 5) << 1, 2, 3, 2, 1, 2, 4, 6, 4, 2, 3, 6, 9, 6, 3, 2, 4, 6, 4, 2, 1, 2, 3, 2, 1);
	kernal_p = kernal_p / 81;
	//rect 
	filter2D(src, dst, CV_8UC1, kernal_p);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	src = dst.clone();

}
private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
	///////cone filter////////
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	Mat kernal_co = (Mat_<float>(5, 5) << 0, 0, 1, 0, 0, 0, 2, 2, 2, 0, 1, 2, 5, 2, 1, 0, 2, 2, 2, 0, 0, 0, 1, 0, 0);
	kernal_co = kernal_co / 25;
	//rect 
	filter2D(src, dst, CV_8UC1, kernal_co);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	src = dst.clone();

}
private: System::Void trackBar17_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	RNG rng;

	int s = trackBar17->Value;
	int p = trackBar12->Value;

	int saltn = src.rows * src.cols * s / 100;
	int peppern = src.rows * src.cols * p / 100;

	for (int i = 0; i < peppern; i++)
	{

		dst.at<uchar>(rng.uniform(0, src.rows), rng.uniform(0, src.cols)) = 0;

	}
	for (int i = 0; i < saltn; i++)
	{

		dst.at<uchar>(rng.uniform(0, src.rows), rng.uniform(0, src.cols)) = 255;
	}
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";

}
private: System::Void trackBar12_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	RNG rng;



	int s = trackBar17->Value;
	int p = trackBar12->Value;

	int saltn = src.rows * src.cols * s / 100;
	int peppern = src.rows * src.cols * p / 100;

	for (int i = 0; i < peppern; i++)
	{

		dst.at<uchar>(rng.uniform(0, src.rows), rng.uniform(0, src.cols)) = 0;

	}
	for (int i = 0; i < saltn; i++)
	{

		dst.at<uchar>(rng.uniform(0, src.rows), rng.uniform(0, src.cols)) = 255;
	}
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";

}
private: System::Void trackBar20_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	RNG rng;



	int sp = trackBar20->Value;
	int sh= trackBar5->Value;
	rng.fill(dst, RNG::NORMAL, sh, sp);
	add(src, dst, dst);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";
}
private: System::Void label50_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar14_Scroll(System::Object^ sender, System::EventArgs^ e) {
	////////////tradtional filter///////////
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	int t = trackBar14->Value;


	Mat kernal_t = (Mat_<float>(5, 5) << 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	kernal_t = kernal_t / 25;
	for (int i = 0; i < t; i++) {
		filter2D(src, dst, CV_8UC1, kernal_t);
	
	}
		imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";

}
private: System::Void trackBar15_Scroll(System::Object^ sender, System::EventArgs^ e) {
	
	//gausian///////
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	int G = trackBar15->Value;


	
	for (int i = 0; i < G; i++) {
		GaussianBlur(src, dst, Size2i(9, 9), 0);
	}
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";

}
private: System::Void trackBar16_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	int M = trackBar16->Value;
	for (int i = 0; i < M; i++) {
		medianBlur(src, dst, 7);
	}
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";


}
private: System::Void trackBar13_Scroll(System::Object^ sender, System::EventArgs^ e) {

	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	int L = trackBar13->Value;


	//Mat kernel_L = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	
	for (int i = 0; i < L; i++) {
	//	filter2D(src, dst, CV_8UC1, kernel_L);
	//Laplacian(src, dst, CV_8UC1);

		Laplacian(src, dst, CV_8UC1);
		dst = src - dst;

	}
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";


}
private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Effect->Visible == true) {
		Effect->Visible = false;



	}
}
private: System::Void label54_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void flowLayoutPanel20_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label27_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar21_Scroll(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button31_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	dst = src.clone();

	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			dst.at<uchar>(i, j) = 255 - src.at<uchar>(i, j);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";


}
private: System::Void panel8_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label59_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar25_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	dst = src.clone();

	int b = trackBar25->Value;
	dst = Mat(src.size(), CV_8UC1, Scalar(0));

	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			dst.at<uchar>(i, j) = src.at<uchar>(i, j) * b / 10 + src2.at<uchar>(i, j) * (10 - b) / 10;


	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";
	

}
private: System::Void trackBar22_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	int max = trackBar22->Value;
	int min = trackBar23->Value;
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++) {
			if ((src.at<uchar>(i, j) >= min) && (src.at<uchar>(i, j) <= max))
				dst.at<uchar>(i, j) = 255;
		
			else
				dst.at<uchar>(i, j) = src.at<uchar>(i, j);
		}
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";


}
private: System::Void trackBar23_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	int max = trackBar22->Value;
	int min = trackBar23->Value;
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++) {
			if ((src.at<uchar>(i, j) >= min) && (src.at<uchar>(i, j) <= max))
				dst.at<uchar>(i, j) = 255;
			else
				dst.at<uchar>(i, j) = src.at<uchar>(i, j);
		}
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";

}
private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	MessageBox::Show("pick second image");
	OpenFileDialog^ image = gcnew OpenFileDialog();// we need a 2nd image so we make another open filedialog and use it to get the new one
	image->Filter = "image Files|*.png;*.jpeg;*.jpg;*.jpe;*.jfif;*.webp";
	if (image->ShowDialog() != System::Windows::Forms::DialogResult::OK)
	{
		return;
	}
	std::string st = "";
	MarshalString(image->FileName, st);
	 src2 = cv::imread(st, 0);//and read it in a 2nd source to use it in the code
	cv::resize(src2, src2, src.size());//we make sure it's of the same size as the first source
		int b = trackBar25->Value;
dst = Mat(src.size(), CV_8UC1, Scalar(0));

	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			dst.at<uchar>(i, j) = src.at<uchar>(i, j) * b / 10 + src2.at<uchar>(i, j) * (10 - b) / 10;


	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";





}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	detect->BringToFront();

if (detect->Visible == false) {
		detect->Visible = true;
	}
if (done->Visible == false) {
	done->Visible = true;

}

}
private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
	
if (detect->Visible == true) {
		detect->Visible = false;
	}

if (done->Visible == true) {
	done->Visible = false;
}
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	liquify->BringToFront();

	if (liquify->Visible == false) {
		liquify->Visible = true;



	}
	if (done->Visible == false) {
		done->Visible = true;

	}


}
private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {


	if (src.empty()) {
		MessageBox::Show("No image ");
		return;
	}
	Mat imgBlur, imgCanny, imgDil, imgErode;
	// Preprocessing

	GaussianBlur(src, imgBlur, cv::Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);

	Mat kernel = getStructuringElement(MORPH_RECT, cv::Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	

	//CONTORS drawing///
	vector<vector<cv::Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	vector<vector<cv::Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	//shape identification
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		string objectType;

		if (area > src.total() / 200)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			boundRect[i] = boundingRect(conPoly[i]);

			int objCor = (int)conPoly[i].size();

			if (objCor == 3) { objectType = "Triangle"; 
			//textBox1->Text = "Triangle";
			}
			else if (objCor == 4)
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; 
				textBox1->Text = "Square";
				}
				else { objectType = "Rectangle";
				textBox1->Text = "Rectangle";
				}
			}
			else if (objCor == 5) { objectType = "Pentagon";
			
			textBox1->Text = "Pentagon";
			
			}
			else if (objCor == 6) { objectType = "Hexagon";
			textBox1->Text = "Hexagon";

			}
			else if (objCor > 6) { objectType = "Circle"; 
			textBox1->Text = "Circle";
			}

			drawContours(dst, conPoly, i, Scalar(255, 0, 255), 2);
			cv::rectangle(dst, boundRect[i].tl(), boundRect[i].br(), Scalar(0), 5);
			cv::putText(dst, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0), 2);
			
		}
	}
	
	


	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";



}
private: System::Void flowLayoutPanel34_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label65_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar26_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("No image ");
		return;
	}

	std::vector<int>params;
	params.push_back(IMWRITE_JPEG_QUALITY);
	params.push_back(Convert::ToInt32(trackBar26->Value)); // that's percentage, so 100 == no compression, 1 == full

	imwrite("test.jpg", dst, params);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";
}

private: System::Void label62_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void flowLayoutPanel36_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void trackBar28_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	int BS = trackBar28->Value;
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++) {
			if ((src.at<uchar>(i, j) & 128) && (BS == 7))
				dst.at<uchar>(i, j) = 255;
			else if ((src.at<uchar>(i, j) & 64) && (BS == 6))
				dst.at<uchar>(i, j) = 255;
			else if ((src.at<uchar>(i, j) & 32) && (BS == 5))
				dst.at<uchar>(i, j) = 255;
			else if ((src.at<uchar>(i, j) & 16) && (BS == 4))
				dst.at<uchar>(i, j) = 255;
			else if ((src.at<uchar>(i, j) & 8) && (BS == 3))
				dst.at<uchar>(i, j) = 255;
			else if ((src.at<uchar>(i, j) & 4) && (BS == 2))
				dst.at<uchar>(i, j) = 255;
			else if ((src.at<uchar>(i, j) & 2) && (BS == 1))
				dst.at<uchar>(i, j) = 255;
			else if ((dst.at<uchar>(i, j) & 1) && (BS == 0))
				dst.at<uchar>(i, j) = 255;
			else
				dst.at<uchar>(i, j) = 0;
		}
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";

}
private: System::Void panel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Histogram->Visible == true) {
		Histogram->Visible = false;



	}
}
private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Histogram->Visible == false) {
		Histogram->Visible = true;
	}
	if (done->Visible == true) {
		done->Visible = false;
	}
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	Mat b_hist;
	int histSize = 256;
	float range[] = { 0, 256 }; //the upper boundary is exclusive
	const float* histRange[] = { range };
	bool uniform = true, accumulate = false;
	int hist_w = 512, hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);

	calcHist(&src, 1, 0, Mat(), b_hist, 1, &histSize, histRange, uniform, accumulate);

	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0, 0));
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < histSize; i++)
	{
		line(histImage, cv::Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			cv::Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 255, 255), 2, 8, 0);
	}
	imwrite("test.jpg", histImage);
	pictureBox4->ImageLocation = "test.jpg";



}
private: System::Void button32_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label58_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button36_Click(System::Object^ sender, System::EventArgs^ e) {
	////////////////////////////laplacian///////////////////////
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	Laplacian(src, dst, CV_8UC1);

	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";
}
private: System::Void button32_Click_2(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}


	Mat kernel_TV = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);

	filter2D(src, dst, CV_8UC1, kernel_TV);//////vertical//////
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";


}
private: System::Void trackBar24_Scroll(System::Object^ sender, System::EventArgs^ e) {

	////////////////// image segmentation///////////////

	
	
	///thresholding method////

	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	Mat dst;
	int th = trackBar24->Value;
	threshold(src, dst, th, 255, THRESH_BINARY);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";




}
private: System::Void label60_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar21_Scroll_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	
	Mat kernel_TH = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);

	filter2D(src, dst, CV_8UC1, kernel_TH);/////horizontal///
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";

}
private: System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}
	
	
	Mat kernel_Td = (Mat_<int>(3, 3) << 2, 1, 0, 1, 0, -1, 0, -1, -2);

	filter2D(src, dst, CV_8UC1, kernel_Td);/////diagonal//////
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;
	infoa->Text = dst.rows.ToString() + "X" + dst.cols.ToString(); +"px";


}
private: System::Void histogramtextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label60_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar27_Scroll(System::Object^ sender, System::EventArgs^ e) {


	int m = getOptimalDFTSize(src.rows);
	int n = getOptimalDFTSize(src.cols);
	Mat padded;
	copyMakeBorder(src, padded, 0, m - src.rows, 0, n - src.cols, 0);
	padded.convertTo(padded, CV_32FC1, 1.0 / 255.0);
	Mat planes[2] = { padded,Mat::zeros(padded.size(),CV_32FC1) };
	Mat complexi;
	merge(planes, 2, complexi);
	dft(complexi, complexi);
	split(complexi, planes);
	////////////////////////
	int cx = complexi.cols / 2;
	int cy = complexi.rows / 2;
	Mat p1(complexi, Rect(0, 0, cx, cy));
	Mat p2(complexi, Rect(cx, 0, cx, cy));
	Mat p3(complexi, Rect(0, cy, cx, cy));
	Mat p4(complexi, Rect(cx, cy, cx, cy));
	Mat temp;
	p1.copyTo(temp);
	p4.copyTo(p1);
	temp.copyTo(p4);
	p2.copyTo(temp);
	p3.copyTo(p2);
	temp.copyTo(p3);
	split(complexi, planes);
	//////////////////////////
	int d0 = trackBar27->Value;

	Mat Hfilter(complexi.size(), CV_32FC1);
	for (int i = 0; i < Hfilter.rows; i++)
	{
		for (int j = 0; j < Hfilter.cols; j++)
		{
			double z1 = i - Hfilter.rows / 2;
			double z2 = j - Hfilter.cols / 2;
			if (sqrt(pow(z1, 2) + pow(z2, 2)) < d0)

				Hfilter.at<float>(i, j) = 0;
			else
				Hfilter.at<float>(i, j) = 1;
		}
	}
	Mat outr, outi;
	multiply(planes[0], Hfilter, outr);
	multiply(planes[1], Hfilter, outi);
	Mat out_planes[2] = { outr,outi };
	Mat out_complexi;
	merge(out_planes, 2, out_complexi);
	idft(out_complexi, out_complexi);
	////////////////////////////////

	split(out_complexi, planes);
	Mat dst;
	magnitude(planes[0], planes[1], dst);
	normalize(dst, dst, 1, 255, NORM_MINMAX);
	cv::resize(dst, dst, src.size());
	
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;


}
private: System::Void trackBar21_Scroll_2(System::Object^ sender, System::EventArgs^ e) {

	int m = getOptimalDFTSize(src.rows);
	int n = getOptimalDFTSize(src.cols);
	Mat padded;
	copyMakeBorder(src, padded, 0, m - src.rows, 0, n - src.cols, 0);
	padded.convertTo(padded, CV_32FC1, 1.0 / 255.0);
	Mat planes[2] = { padded,Mat::zeros(padded.size(),CV_32FC1) };
	Mat complexi;
	merge(planes, 2, complexi);
	dft(complexi, complexi);
	split(complexi, planes);
	////////////////////////
	int cx = complexi.cols / 2;
	int cy = complexi.rows / 2;
	Mat p1(complexi, Rect(0, 0, cx, cy));
	Mat p2(complexi, Rect(cx, 0, cx, cy));
	Mat p3(complexi, Rect(0, cy, cx, cy));
	Mat p4(complexi, Rect(cx, cy, cx, cy));
	Mat temp;
	p1.copyTo(temp);
	p4.copyTo(p1);
	temp.copyTo(p4);
	p2.copyTo(temp);
	p3.copyTo(p2);
	temp.copyTo(p3);
	split(complexi, planes);
	//////////////////////////
	int d0 = trackBar21->Value;

	Mat Hfilter(complexi.size(), CV_32FC1);
	for (int i = 0; i < Hfilter.rows; i++)
	{
		for (int j = 0; j < Hfilter.cols; j++)
		{
			double z1 = i - Hfilter.rows / 2;
			double z2 = j - Hfilter.cols / 2;
			if (sqrt(pow(z1, 2) + pow(z2, 2)) < d0)

				Hfilter.at<float>(i, j) = 1;
			else
				Hfilter.at<float>(i, j) = 0;
		}
	}
	Mat outr, outi;
	multiply(planes[0], Hfilter, outr);
	multiply(planes[1], Hfilter, outi);
	Mat out_planes[2] = { outr,outi };
	Mat out_complexi;
	merge(out_planes, 2, out_complexi);
	idft(out_complexi, out_complexi);
	////////////////////////////////

	split(out_complexi, planes);
	Mat dst;
	magnitude(planes[0], planes[1], dst);
	normalize(dst, dst, 1, 255, NORM_MINMAX);
	cv::resize(dst, dst, src.size());

	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;

}
private: System::Void flowLayoutPanel27_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label65_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button10_Click_1(System::Object^ sender, System::EventArgs^ e) {

	if (liquify->Visible == true) {
		liquify->Visible = false;



	}
	if (done->Visible == true) {
		done->Visible = false;
	}


}

private: System::Void flowLayoutPanel17_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label61_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label68_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button16_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (src.empty()) {
			MessageBox::Show("no image ");
			return;
		}
	    src = dst.clone();

}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void bright_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar29_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int I = trackBar29->Value;
	float b = 1.02;
	float c = 255.0 / (pow(b, I) - 1);

	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	dst = Mat(src.size(), CV_32FC1, Scalar(0));
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			dst.at<float>(i, j) = c * powf(src.at<uchar>(i, j), I);
	normalize(dst, dst, 0, 255, NORM_MINMAX);
	convertScaleAbs(dst, dst);
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;

}
private: System::Void flowLayoutPanel21_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
/*private: System::Void button16_Click_2(System::Object^ sender, System::EventArgs^ e) {
	//Mat image1 = imread("input/image_2.jpg");
	//Mat img_gray1;
	//cvtColor(image1, img_gray1, COLOR_BGR2GRAY);
	Mat thresh1;
	threshold(src, dst, 150, 255, THRESH_BINARY);
	vector<vector<cv::Point>> contours2;
	vector<Vec4i> hierarchy2;
	findContours(thresh1, contours2, hierarchy2, RETR_TREE, CHAIN_APPROX_NONE);
	//Mat image_copy2 = image1.clone();
	drawContours(dst, contours2, -1, Scalar(0, 255, 0), 2);
	//imshow("None approximation", image_copy2);
	//waitKey(0);
	//imwrite("contours_none_image1.jpg", image_copy2);
	//destroyAllWindows();
	//Mat image_copy3 = image1.clone();
	for (int i = 0; i < contours2.size(); i = i + 1) {
		for (int j = 0; j < contours2[i].size(); j = j + 1) {
			circle(dst, (contours2[i][0], contours2[i][1]), 2, Scalar(0, 255, 0), 2);
		}
	}
	//imshow("CHAIN_APPROX_SIMPLE Point only", image_copy3);
	//waitKey(0);
//	imwrite("contour_point_simple.jpg", image_copy3);
	//destroyAllWindows();
	imwrite("test.jpg", dst);
	pictureBox2->ImageLocation = "test.jpg";
	ofd->FileName = pictureBox2->ImageLocation;


}*/
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
