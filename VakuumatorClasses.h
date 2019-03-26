//---------------------------------------------------------------------------

#ifndef VakuumatorClassesH
#define VakuumatorClassesH
#include "Unit1.h"
#include "vcl.h"
//---------------------------------------------------------------------------
class GazoohWaterClass{
private:
	bool IsOn;
	bool IsAuto;
	float Tin,Tinsim,Tout,Tdiffzd,P;
	int Klapan;
	int Nagrev;
	void SimulationTP();
public:
	GazoohWaterClass();
	~GazoohWaterClass();
	void OneMoreMoment();
	void TurnOn();
	float GetTin();
	float GetTout();
	float GetP();
	int GetKlapan();
	int GetNagrev();
	void SetTinsim(float newTinsim);
	void SetKlapan(int newKlapan);
	void SetTdiffzd(float newTdiffzd);
	void SetAutoMode(bool newIsAuto);
};
//---------------------------------------------------------------------------
class VakuumatorClass{
private:
	int mode;
	bool IsOn;
	bool IsAutoP;
	bool IsAutoF;
	bool IsAutoZD;
	bool Done;
	float P,Pzd,F,Fzd;
	int KlapanP,KlapanPlittle,KlapanF;
	int Kipenie;

	void Regtor();
	void SimulationPF();
	void FormingZD();
	void Down();
	void Up();
public:
	TImage *Vak;
	TImage *Head;
	VakuumatorClass();
	~VakuumatorClass();
	int OneMoreMoment();
	void TurnOn();
	void ImageSettings();

	float GetP();
	float GetF();
	float GetPzd();
	float GetFzd();
	float GetKlapanP();
	int GetKlapanPintBig();
	int GetKlapanPintLittle();
	int GetKlapanF();
	int GetKipenie();
	void SetKlapanP(int newKlapan);
	void SetKlapanPlittle(int newKlapan);
	void SetKlapanF(int newKlapan);
	void SetPzd(float newPzd);
	void SetFzd(float newFzd);
	void SetAutoModeP(bool newIsAuto);
	void SetAutoModeF(bool newIsAuto);
	void SetAutoZDMode(bool newIsAuto);
};
//---------------------------------------------------------------------------
#endif
