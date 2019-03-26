//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TVakuumatorForm *VakuumatorForm;
GazoohWaterClass GazoohWater;
VakuumatorClass Vakuumator;
int sec;
void UpdateUI();
void Wasted();
void fixKey(TObject *Sender, System::WideChar &Key);
//---------------------------------------------------------------------------
__fastcall TVakuumatorForm::TVakuumatorForm(TComponent* Owner)
	: TForm(Owner)
{
DoubleBuffered=1;
VakuumatorForm->Image1->Visible=0;
VakuumatorForm->Image1->AutoSize=1;
if(FileExists("files/wasted.png")){
	VakuumatorForm->Image1->Picture->LoadFromFile("files/wasted.png");
}
VakuumatorForm->Chart1->Series[0]->Clear();
VakuumatorForm->Chart2->Series[0]->Clear();
Vakuumator.Vak=new TImage(VakuumatorForm);
Vakuumator.Head=new TImage(VakuumatorForm);
Vakuumator.Vak->Parent=VakuumatorForm;
Vakuumator.Head->Parent=VakuumatorForm;
Vakuumator.ImageSettings();
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::Timer1Timer(TObject *Sender)
{
GazoohWater.OneMoreMoment();
int VakMode=Vakuumator.OneMoreMoment();
UpdateUI();
sec++;
if(VakMode==0){
	VakuumatorForm->Timer1->Enabled=0;
	VakuumatorForm->Button3->Enabled=1;
}
}
//---------------------------------------------------------------------------
void UpdateUI(){
VakuumatorForm->Label1->Caption=VakuumatorForm->Label1->Caption.sprintf(L"Tвх (С) = %0.2f",GazoohWater.GetTin());
VakuumatorForm->Label2->Caption=VakuumatorForm->Label2->Caption.sprintf(L"Tвых (С) = %0.2f",GazoohWater.GetTout());
VakuumatorForm->Label5->Caption=VakuumatorForm->Label5->Caption.sprintf(L"Tразн (С) = %0.2f",GazoohWater.GetTout()-GazoohWater.GetTin());
VakuumatorForm->Label3->Caption=VakuumatorForm->Label3->Caption.sprintf(L"P (Па) = %0.2f",GazoohWater.GetP());
VakuumatorForm->Label4->Caption="Клапан (%) = "+IntToStr(GazoohWater.GetKlapan());
VakuumatorForm->TrackBar1->Position=GazoohWater.GetKlapan();

VakuumatorForm->Label6->Caption=VakuumatorForm->Label6->Caption.sprintf(L"Р (Па) = %0.3f",Vakuumator.GetP());
VakuumatorForm->Label7->Caption=VakuumatorForm->Label7->Caption.sprintf(L"Клапан Р (\%%) = %0.4f",Vakuumator.GetKlapanP());
VakuumatorForm->Label8->Caption=VakuumatorForm->Label8->Caption.sprintf(L"F (м3/ч) = %0.2f",Vakuumator.GetF());
VakuumatorForm->Label9->Caption="Клапан F (%) = "+IntToStr(Vakuumator.GetKlapanF());
VakuumatorForm->TrackBar2->Position=Vakuumator.GetKlapanPintBig();
VakuumatorForm->TrackBar3->Position=Vakuumator.GetKlapanPintLittle();
VakuumatorForm->TrackBar4->Position=Vakuumator.GetKlapanF();
if(!VakuumatorForm->LabeledEdit3->Enabled){
	VakuumatorForm->LabeledEdit3->Text=Vakuumator.GetPzd();
}
if(!VakuumatorForm->LabeledEdit4->Enabled){
	VakuumatorForm->LabeledEdit4->Text=Vakuumator.GetFzd();
}

VakuumatorForm->Chart1->Series[0]->AddXY(sec,Vakuumator.GetP());
VakuumatorForm->Chart2->Series[0]->AddXY(sec,Vakuumator.GetF());

int Nagrev=GazoohWater.GetNagrev();
if((Nagrev>=0)&&(Nagrev<255)){
	VakuumatorForm->Label10->Color=(TColor)RGB(255,255-Nagrev,255-Nagrev);
}else if(Nagrev>=255){
	VakuumatorForm->Label10->Color=(TColor)RGB(255,0,0);
	Wasted();
}

Nagrev=(Vakuumator.GetKipenie()-1)*2.55;
if((Nagrev>=0)&&(Nagrev<255)){
	VakuumatorForm->Label11->Color=(TColor)RGB(255,255-Nagrev,255-Nagrev);
}else if(Nagrev>=255){
	VakuumatorForm->Label11->Color=(TColor)RGB(255,0,0);
	Wasted();
}
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::CheckBox1Click(TObject *Sender)
{
VakuumatorForm->TrackBar1->Enabled=!VakuumatorForm->CheckBox1->Checked;
GazoohWater.SetAutoMode(VakuumatorForm->CheckBox1->Checked);
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::TrackBar1Change(TObject *Sender)
{
GazoohWater.SetKlapan(VakuumatorForm->TrackBar1->Position);
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::Button1Click(TObject *Sender)
{
GazoohWater.SetTinsim(StrToFloat(VakuumatorForm->LabeledEdit1->Text));
GazoohWater.SetTdiffzd(StrToFloat(VakuumatorForm->LabeledEdit2->Text));
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::FormClose(TObject *Sender, TCloseAction &Action)
{
if(Vakuumator.Head){
delete Vakuumator.Head;
Vakuumator.Head=NULL;
}
if(Vakuumator.Vak){
delete Vakuumator.Vak;
Vakuumator.Vak=NULL;
}
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::Button2Click(TObject *Sender)
{
Vakuumator.SetPzd(StrToFloat(VakuumatorForm->LabeledEdit3->Text));
Vakuumator.SetFzd(StrToFloat(VakuumatorForm->LabeledEdit4->Text));
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::CheckBox2Click(TObject *Sender)
{
VakuumatorForm->TrackBar2->Enabled=!VakuumatorForm->CheckBox2->Checked;
VakuumatorForm->TrackBar3->Enabled=!VakuumatorForm->CheckBox2->Checked;
Vakuumator.SetAutoModeP(VakuumatorForm->CheckBox2->Checked);
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::CheckBox3Click(TObject *Sender)
{
VakuumatorForm->TrackBar4->Enabled=!VakuumatorForm->CheckBox3->Checked;
Vakuumator.SetAutoModeF(VakuumatorForm->CheckBox3->Checked);
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::TrackBar2Change(TObject *Sender)
{
Vakuumator.SetKlapanP(VakuumatorForm->TrackBar2->Position);
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::TrackBar3Change(TObject *Sender)
{
Vakuumator.SetKlapanPlittle(VakuumatorForm->TrackBar3->Position);
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::TrackBar4Change(TObject *Sender)
{
Vakuumator.SetKlapanF(VakuumatorForm->TrackBar4->Position);
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::Button3Click(TObject *Sender)
{
sec=0;
VakuumatorForm->Chart1->Series[0]->Clear();
VakuumatorForm->Chart2->Series[0]->Clear();
//VakuumatorForm->CheckBox4->Enabled=0;
Vakuumator.SetAutoZDMode(VakuumatorForm->CheckBox4->Checked);
Vakuumator.TurnOn();
GazoohWater.TurnOn();
VakuumatorForm->Timer1->Enabled=1;
VakuumatorForm->Button3->Enabled=0;
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::CheckBox4Click(TObject *Sender)
{
if(VakuumatorForm->CheckBox4->Checked){
	VakuumatorForm->CheckBox2->Checked=1;
	VakuumatorForm->TrackBar2->Enabled=!VakuumatorForm->CheckBox2->Checked;
	VakuumatorForm->TrackBar3->Enabled=!VakuumatorForm->CheckBox2->Checked;
	Vakuumator.SetAutoModeP(VakuumatorForm->CheckBox2->Checked);
	VakuumatorForm->CheckBox3->Checked=1;
	VakuumatorForm->TrackBar4->Enabled=!VakuumatorForm->CheckBox3->Checked;
	Vakuumator.SetAutoModeF(VakuumatorForm->CheckBox3->Checked);
	VakuumatorForm->CheckBox2->Enabled=0;
	VakuumatorForm->CheckBox3->Enabled=0;
	VakuumatorForm->LabeledEdit3->Enabled=0;
	VakuumatorForm->LabeledEdit4->Enabled=0;
	VakuumatorForm->Button2->Enabled=0;
}else{
	VakuumatorForm->CheckBox2->Enabled=1;
	VakuumatorForm->CheckBox3->Enabled=1;
	VakuumatorForm->LabeledEdit3->Enabled=1;
	VakuumatorForm->LabeledEdit4->Enabled=1;
	VakuumatorForm->Button2->Enabled=1;
}
Vakuumator.SetAutoZDMode(VakuumatorForm->CheckBox4->Checked);
}
//---------------------------------------------------------------------------
void Wasted(){
if(FileExists("files/GTA 5 wasted  sound effect.wav")){
	PlaySound(L"files/GTA 5 wasted  sound effect.wav", NULL, SND_FILENAME | SND_ASYNC);
}
VakuumatorForm->Timer1->Enabled=0;
VakuumatorForm->GroupBox1->Visible=0;
VakuumatorForm->GroupBox2->Visible=0;
VakuumatorForm->Chart1->Visible=0;
VakuumatorForm->Chart2->Visible=0;
VakuumatorForm->Button3->Visible=0;
VakuumatorForm->Image1->Visible=1;
VakuumatorForm->Image1->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::Image1Click(TObject *Sender)
{
VakuumatorForm->Close();
}
//---------------------------------------------------------------------------
void fixKey(TObject *Sender, System::WideChar &Key){
if ((Key >= '0') && (Key <= '9')){  // цифры
}else if (Key == 8){  // <-
}else if ((Key == '.') || (Key == ',')){ // запятая
	if (((TLabeledEdit*)Sender)->Text.Pos(FormatSettings.DecimalSeparator)!=0){ // если запятая уже есть
		Key = 0;
	}else{ // если ещё нет
		if(((TLabeledEdit*)Sender)->GetTextLen()>0){
			Key = FormatSettings.DecimalSeparator;
		}else{
			Key = 0;
		}
	}
}else Key = 0; // не цифра
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::LabeledEdit3KeyPress(TObject *Sender, System::WideChar &Key)
{
fixKey(Sender,Key);
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::LabeledEdit4KeyPress(TObject *Sender, System::WideChar &Key)
{
fixKey(Sender,Key);
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::LabeledEdit2KeyPress(TObject *Sender, System::WideChar &Key)
{
fixKey(Sender,Key);
}
//---------------------------------------------------------------------------
void __fastcall TVakuumatorForm::LabeledEdit1KeyPress(TObject *Sender, System::WideChar &Key)
{
fixKey(Sender,Key);
}
//---------------------------------------------------------------------------

