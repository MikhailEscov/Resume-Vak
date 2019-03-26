//---------------------------------------------------------------------------
#pragma hdrstop
#include "VakuumatorClasses.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
GazoohWaterClass::GazoohWaterClass(){
this->IsOn=0;
this->IsAuto=1;
this->Tin=this->Tout=this->P=0;
this->Tinsim=23;
this->Klapan=0;
this->Tdiffzd=50;
this->Nagrev=0;
}
//---------------------------------------------------------------------------
GazoohWaterClass::~GazoohWaterClass(){
}
//---------------------------------------------------------------------------
void GazoohWaterClass::OneMoreMoment(){
if(this->IsOn){
	if(this->IsAuto){
		if(this->Klapan<=0){
			this->Klapan=this->Tinsim/35*100;//Чем выше температура входящей воды, тем больше нужно открыть клапан(пропорционально)
	//		this->Klapan+=(this->Tdiffzd-(this->Tout-this->Tin));
		}
		if((this->Tout-this->Tin)>this->Tdiffzd+0.3+(1e-8)){
			if(this->Klapan<100){
				this->Klapan++;
			}
		}else if((this->Tout-this->Tin)<this->Tdiffzd-0.3-(1e-8)){
			if(this->Klapan>1){
				this->Klapan--;
			}
		}
	}else{
		if(this->Klapan<=0){
			this->Nagrev+=4;
		}
	}
	if(this->Nagrev>0){
		this->Nagrev--;
	}
}
this->SimulationTP();
}
//---------------------------------------------------------------------------
void GazoohWaterClass::SimulationTP(){
if((this->Klapan>0)&&this->IsOn){
	this->Tin=this->Tinsim;
	this->Tin+=(std::random(2)==1?1:-1)*((float)std::random(100)/10000);
	if(this->Tin<0-(1e-8)){
		this->Tin=((float)std::random(100)/10000);
	}else if(this->Tin>35+(1e-8)){
		this->Tin=35-((float)std::random(100)/10000);
	}
	this->Tout=50+(float)this->Tin/35*7+(float)(100-this->Klapan)/100*28+(std::random(2)==1?1:-1)*((float)std::random(100)/10000);;
	this->P=((float)this->Klapan/100*740)+(std::random(2)==1?1:-1)*((float)std::random(100)/10000);
}else{
	this->Tin=this->Tout=this->P=0;
}
}
//---------------------------------------------------------------------------
void GazoohWaterClass::TurnOn(){
this->IsOn=1;
this->Tinsim=std::random(35);
//this->Klapan=1;
}
//---------------------------------------------------------------------------
float GazoohWaterClass::GetTin(){
return this->Tin;
}
//---------------------------------------------------------------------------
float GazoohWaterClass::GetTout(){
return this->Tout;
}
//---------------------------------------------------------------------------
float GazoohWaterClass::GetP(){
return this->P;
}
//---------------------------------------------------------------------------
int GazoohWaterClass::GetKlapan(){
return this->Klapan;
}
//---------------------------------------------------------------------------
int GazoohWaterClass::GetNagrev(){
return this->Nagrev;
}
//---------------------------------------------------------------------------
void GazoohWaterClass::SetTinsim(float newTinsim){
if((newTinsim>0-(1e-8))&&(newTinsim<35+(1e-8))){
	this->Tinsim=newTinsim;
}
}
//---------------------------------------------------------------------------
void GazoohWaterClass::SetKlapan(int newKlapan){
if((newKlapan>=0)&&(newKlapan<=100)){
	this->Klapan=newKlapan;
}
}
//---------------------------------------------------------------------------
void GazoohWaterClass::SetTdiffzd(float newTdiffzd){
if(newTdiffzd>0-(1e-8)){
	this->Tdiffzd=newTdiffzd;
}
}
//---------------------------------------------------------------------------
void GazoohWaterClass::SetAutoMode(bool newIsAuto){
this->IsAuto=newIsAuto;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
VakuumatorClass::VakuumatorClass(){
this->mode=0;
this->IsOn=0;
this->IsAutoP=1;
this->IsAutoF=1;
this->Done=0;
this->P=this->Pzd=this->F=this->Fzd=0;
this->KlapanP=this->KlapanF=this->Kipenie=0;
}
//---------------------------------------------------------------------------
VakuumatorClass::~VakuumatorClass(){
}
//---------------------------------------------------------------------------
void VakuumatorClass::ImageSettings(){
this->Vak->AutoSize=1;
this->Vak->Left=0;
this->Vak->Top=0;
this->Vak->Visible=1;
this->Head->AutoSize=1;
this->Head->Left=0;
this->Head->Top=-25;
this->Head->Visible=1;
if(FileExists("files/vak.png")){
	this->Vak->Picture->LoadFromFile("files/vak.png");
}
if(FileExists("files/head.png")){
	this->Head->Picture->LoadFromFile("files/head.png");
}
}
//---------------------------------------------------------------------------
int VakuumatorClass::OneMoreMoment(){
switch (this->mode) {
case 0://off
break;
case 1://down
	this->Down();
	this->SimulationPF();
break;
case 2://work
	this->Regtor();
	this->SimulationPF();
	if(this->IsAutoZD){
		this->FormingZD();
	}
	if((this->Done)&&(fabs(this->P-101325)<(1e-8))){
		this->mode=3;
		this->IsOn=0;
	}
break;
case 3://up
	this->Up();
	this->SimulationPF();
break;
default:
break;
}
return this->mode;
}
//---------------------------------------------------------------------------
void VakuumatorClass::Regtor(){
if(this->IsOn){
	if((this->IsAutoP)&&(this->Kipenie<100)){//P
		float diff=this->P-this->Pzd;
		float Klval=(float)(this->KlapanPlittle)*0.101325;

		if(
		(
		(diff-Klval>(1e-8))&&
		(fabs(diff-Klval)>0.101325+(1e-8))
		)||(
		(diff-Klval<-(1e-8))&&
		(fabs(diff-Klval)>101.223675+(1e-8))
		)
		)
		{
			if(fabs(diff)/101.223675>2+(1e-8)){
				this->KlapanP+=(diff>0?-1:1)*(fabs(diff)/101.223675/2);
			}else{
				this->KlapanP+=(diff>0?-1:1);
			}
		}
		if((fabs(diff)>0.101325+(1e-8))&&
		(fabs(diff)<101.325-(1e-8))){
			if(fabs(diff)/0.101325>2+(1e-8)){
				this->KlapanPlittle+=(diff>0?-1:1)*(fabs(diff)/0.101325/2);
			}else{
				this->KlapanPlittle+=(diff>0?-1:1);
			}
		}
		if((this->KlapanP<1)&&(this->KlapanPlittle<1)){
			this->KlapanP=0;
			this->KlapanPlittle=1;
		}else if(this->KlapanP<0){
			this->KlapanP=0;
		}else if(this->KlapanPlittle<0){
			this->KlapanPlittle=0;
		}

		if(this->KlapanP>1000){
			this->KlapanP=1000;
		}
		if(this->KlapanPlittle>1000){
			this->KlapanPlittle=1000;
		}
	}
	if((this->IsAutoF)&&(this->Kipenie<100)){//F
		if(this->KlapanF<=0){
			this->KlapanF=1;
		}
		if(this->F>this->Fzd+0.9+(1e-8)){
			if(this->KlapanF>1){
				this->KlapanF--;
			}
		}else if(this->F<this->Fzd-0.9-(1e-8)){
			if(this->KlapanF<100){
				this->KlapanF++;
			}
		}
	}
}
}
//---------------------------------------------------------------------------
void VakuumatorClass::SimulationPF(){
float Ptemp=this->P;
if(this->IsOn){
	if((this->KlapanP>0)||(this->KlapanPlittle>0)){//((101325-101.325)/1000)) and 101325/1000
		this->P=(float)(this->KlapanP)*101.223675+(float)(this->KlapanPlittle)*0.101325;
		this->P+=(std::random(2)==1?1:-1)*((float)std::random(100)/10000);
		if(this->P<0-(1e-8)){
			this->P=0+((float)std::random(100)/10000);
		}else if(this->P>101325+(1e-8)){
			this->P=101325-((float)std::random(100)/10000);
		}
	}else{
		this->P=0;
	}
	if(this->KlapanF>0){
		this->F=(float)(this->KlapanF*90)/100;
		this->F+=(std::random(2)==1?1:-1)*((float)std::random(100)/10000);
		if(this->F<0-(1e-8)){
			this->F=0+((float)std::random(100)/10000);
		}else if(this->F>90+(1e-8)){
			this->F=90-((float)std::random(100)/10000);
		}
	}else{
		this->F=0;
	}
}else{
	this->KlapanP=1000;
	this->KlapanPlittle=1000;
	this->KlapanF=0;
	this->P=101325;
	this->F=0;
}

if(this->P<Ptemp-1-(1e-8)){
	if(this->Kipenie<100){
		this->Kipenie+=std::random(int(fabs(this->P-Ptemp)/100));
		//this->Kipenie+=std::random(2)+std::random(2);//0=25%; 1=50%; 2=25%
	}else{
		this->Kipenie-=std::random(10);
		if(this->Kipenie<0){
			this->Kipenie=0;
		}
	}
}else{
	this->Kipenie-=std::random(10);
	if(this->Kipenie<0){
		this->Kipenie=0;
	}
}

if((this->P<60+(1e-8))&&(this->Kipenie==0)){//Достигнут вакуум, пожар угас = вакуумирование завершено
	this->Done=1;
}

}
//---------------------------------------------------------------------------
void VakuumatorClass::FormingZD(){
if(!this->Done){
	if(this->Pzd>60+(1e-8)){
		float diff=this->Pzd-60;
		if(diff>2-(1e-8)){
			int range=(100-this->Kipenie)*10;
			if(range>0){//если кипение превысило 100
				float minus=diff/2;
				if((float)range<minus-(1e-8)){
					minus=std::random(range);
				}
				this->Pzd-=minus;
			}
		}else{
			this->Pzd-=1;
		}
	}
	this->Fzd=(this->Pzd-60)/(101325-60)*90;
	if(this->Fzd<0-(1e-8)){
		this->Fzd=0;
	}
}else{
	if(this->Pzd<101325-(1e-8)){
		this->Pzd+=std::random(1000);
		if(this->Pzd>101325+(1e-8)){
			this->Pzd=101325;
		}
	}
	this->Fzd=0;
}
}
//---------------------------------------------------------------------------
void VakuumatorClass::Down(){
if(this->Head){
	if(this->Head->Top<0){
		this->Head->Top++;
	}else{
		this->mode=2;
		this->IsOn=1;
	}
}else{
	this->mode=0;
}
}
//---------------------------------------------------------------------------
void VakuumatorClass::Up(){
if(this->Head){
	if(this->Head->Top>-25){
		this->Head->Top--;
	}else{
		this->mode=0;
	}
}else{
	this->mode=0;
}
}
//---------------------------------------------------------------------------
void VakuumatorClass::TurnOn(){
this->KlapanP=this->KlapanPlittle=this->KlapanF=1000;
this->Kipenie=0;
this->Pzd=101325;
this->Fzd=90;
this->mode=1;
this->Done=0;
}
//---------------------------------------------------------------------------
float VakuumatorClass::GetP(){
return this->P;
}
//---------------------------------------------------------------------------
float VakuumatorClass::GetF(){
return this->F;
}
//---------------------------------------------------------------------------
float VakuumatorClass::GetPzd(){
return this->Pzd;
}
//---------------------------------------------------------------------------
float VakuumatorClass::GetFzd(){
return this->Fzd;
}
//---------------------------------------------------------------------------
float VakuumatorClass::GetKlapanP(){
return ((101325-101.325)/101325*this->KlapanP+101.325/101325*this->KlapanPlittle)/10;
}
//---------------------------------------------------------------------------
int VakuumatorClass::GetKlapanPintBig(){
return this->KlapanP;
}
//---------------------------------------------------------------------------
int VakuumatorClass::GetKlapanPintLittle(){
return this->KlapanPlittle;
}
//---------------------------------------------------------------------------
int VakuumatorClass::GetKlapanF(){
return this->KlapanF;
}
//---------------------------------------------------------------------------
int VakuumatorClass::GetKipenie(){
return this->Kipenie;
}
//---------------------------------------------------------------------------
void VakuumatorClass::SetKlapanPlittle(int newKlapan){
this->KlapanPlittle=newKlapan;
}
//---------------------------------------------------------------------------
void VakuumatorClass::SetKlapanP(int newKlapan){
this->KlapanP=newKlapan;
}
//---------------------------------------------------------------------------
void VakuumatorClass::SetKlapanF(int newKlapan){
this->KlapanF=newKlapan;
}
//---------------------------------------------------------------------------
void VakuumatorClass::SetPzd(float newPzd){
this->Pzd=newPzd;
}
//---------------------------------------------------------------------------
void VakuumatorClass::SetFzd(float newFzd){
this->Fzd=newFzd;
}
//---------------------------------------------------------------------------
void VakuumatorClass::SetAutoModeP(bool newIsAuto){
this->IsAutoP=newIsAuto;
}
//---------------------------------------------------------------------------
void VakuumatorClass::SetAutoModeF(bool newIsAuto){
this->IsAutoF=newIsAuto;
}
//---------------------------------------------------------------------------
void VakuumatorClass::SetAutoZDMode(bool newIsAuto){
this->IsAutoZD=newIsAuto;
}
//---------------------------------------------------------------------------
