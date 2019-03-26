//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include "VakuumatorClasses.h"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
//---------------------------------------------------------------------------
class TVakuumatorForm : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TTrackBar *TrackBar1;
	TLabel *Label4;
	TCheckBox *CheckBox1;
	TLabeledEdit *LabeledEdit1;
	TButton *Button1;
	TTimer *Timer1;
	TLabeledEdit *LabeledEdit2;
	TLabel *Label5;
	TGroupBox *GroupBox2;
	TLabel *Label6;
	TLabel *Label7;
	TTrackBar *TrackBar2;
	TTrackBar *TrackBar3;
	TLabeledEdit *LabeledEdit3;
	TLabel *Label8;
	TLabel *Label9;
	TTrackBar *TrackBar4;
	TLabeledEdit *LabeledEdit4;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TButton *Button2;
	TButton *Button3;
	TChart *Chart1;
	TLineSeries *Series1;
	TChart *Chart2;
	TLineSeries *LineSeries1;
	TCheckBox *CheckBox4;
	TImage *Image1;
	TLabel *Label10;
	TLabel *Label11;
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall TrackBar3Change(TObject *Sender);
	void __fastcall TrackBar4Change(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall CheckBox4Click(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall LabeledEdit3KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall LabeledEdit4KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall LabeledEdit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall LabeledEdit1KeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TVakuumatorForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVakuumatorForm *VakuumatorForm;
//---------------------------------------------------------------------------
#endif

