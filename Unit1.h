#ifndef Unit1H
#define Unit1H

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>

class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMemo *Memo1;
    TMainMenu *MainMenu1;
    TMenuItem *Function1;
    TMenuItem *Sin1;
    TMenuItem *Cos1;
    TMenuItem *Ln1;
    TMenuItem *Interval1;
    TMenuItem *Set1;
    TMenuItem *Compute1;
    TMenuItem *SimpsonIntegral1;
    void __fastcall Sin1Click(TObject *Sender);
    void __fastcall Cos1Click(TObject *Sender);
    void __fastcall Exp1Click(TObject *Sender);
    void __fastcall Ln1Click(TObject *Sender);
    void __fastcall Set1Click(TObject *Sender);
    void __fastcall Tabulate1Click(TObject *Sender);
    void __fastcall SimpsonIntegral1Click(TObject *Sender);

private:
    enum TFunc { ftSin, ftCos, ftExp, ftLn };
    TFunc  cur = ftSin;
    double a = 0.0, b = 3.14159265358979323846;
    int    n = 100;

    double f(double x) const;
    bool   ValidateDomain() const;
    void   EnsureEvenN();
    void   PrintHeader(const UnicodeString& title);

public:
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;

#endif
