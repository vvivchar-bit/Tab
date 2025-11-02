 #include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <math.h>
#include <algorithm>

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

// ===== Вибір функції =====
void __fastcall TForm1::Sin1Click(TObject *Sender)
{
    cur = ftSin;
    Memo1->Lines->Add(L"Selected: sin(x)");
}
void __fastcall TForm1::Cos1Click(TObject *Sender)
{
    cur = ftCos;
    Memo1->Lines->Add(L"Selected: cos(x)");
}
void __fastcall TForm1::Exp1Click(TObject *Sender)
{
    cur = ftExp;
    Memo1->Lines->Add(L"Selected: exp(x)");
}
void __fastcall TForm1::Ln1Click(TObject *Sender)
{
    cur = ftLn;
    Memo1->Lines->Add(L"Selected: ln(x)");
}

// ===== Встановлення інтервалу =====
void __fastcall TForm1::Set1Click(TObject *Sender)
{
    try {
        a = StrToFloat(InputBox(L"Set interval", L"Enter a:", FloatToStr(a)));
        b = StrToFloat(InputBox(L"Set interval", L"Enter b:", FloatToStr(b)));
        n = StrToInt(InputBox(L"Set interval", L"Enter n:", IntToStr(n)));
    } catch (...) {
        Application->MessageBox(L"Некоректне введення або скасовано.",
                                L"Input error", MB_ICONWARNING);
        return;
    }

    Memo1->Lines->Add(L"Interval set to [" + FloatToStr(a) + L"; " +
                      FloatToStr(b) + L"], n = " + IntToStr(n));
}

// ===== Допоміжні =====
double TForm1::f(double x) const
{
    switch (cur) {
        case ftSin: return sin(x);
        case ftCos: return cos(x);
        case ftExp: return exp(x);
        case ftLn:  return log(x);
    }
    return 0.0;
}

bool TForm1::ValidateDomain() const
{
    if (cur == ftLn)
        return std::min(a, b) > 0.0;
    return true;
}

void TForm1::EnsureEvenN()
{
    if (n < 2) n = 2;
    if (n % 2 != 0) n += 1;
}

void TForm1::PrintHeader(const UnicodeString& title)
{
    UnicodeString fn = (cur==ftSin)? L"sin(x)" :
                       (cur==ftCos)? L"cos(x)" :
                       (cur==ftExp)? L"exp(x)" : L"ln(x)";

    Memo1->Lines->Add(L"--------------------------------");
    Memo1->Lines->Add(title);
    Memo1->Lines->Add(L"Function: " + fn);
    Memo1->Lines->Add(L"Interval: [" + FloatToStr(a) + L"; " +
                      FloatToStr(b) + L"], n = " + IntToStr(n));
    Memo1->Lines->Add(L"--------------------------------");
}

// ===== Табуляція =====
void __fastcall TForm1::Tabulate1Click(TObject *Sender)
{
    if (!ValidateDomain()) {
        Application->MessageBox(L"ln(x) вимагає x>0 на всьому відрізку",
                                L"Domain error", MB_ICONERROR);
        return;
    }
    EnsureEvenN();
    const double h = (b - a) / n;

    Memo1->Lines->Clear();
    PrintHeader(L"Tabulation");
    Memo1->Lines->Add(L"x\tf(x)");

    for (int i = 0; i <= n; ++i) {
        const double x = a + i*h;
        Memo1->Lines->Add(FloatToStrF(x, ffGeneral, 15, 8) + L"\t" +
                          FloatToStrF(f(x), ffGeneral, 15, 8));
    }
}

// ===== Інтеграл Сімпсона =====
void __fastcall TForm1::SimpsonIntegral1Click(TObject *Sender)
{
    if (!ValidateDomain()) {
        Application->MessageBox(L"ln(x) вимагає x>0 на всьому відрізку",
                                L"Domain error", MB_ICONERROR);
        return;
    }
    EnsureEvenN();
    const double h = (b - a) / n;

    double sumOdd = 0.0, sumEven = 0.0;
    for (int i = 1; i < n; ++i) {
        const double xi = a + i*h;
        if (i % 2) sumOdd += f(xi);
        else       sumEven += f(xi);
    }
    const double I = (h/3.0) * (f(a) + f(b) + 4*sumOdd + 2*sumEven);

    Memo1->Lines->Clear();
    PrintHeader(L"Simpson Integral");
    Memo1->Lines->Add(L"Integral ≈ " + FloatToStrF(I, ffGeneral, 15, 10));
}




