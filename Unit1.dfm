object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Tabulation and Simpson Integration.'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  TextHeight = 15
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 624
    Height = 441
    Align = alClient
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Consolas'
    Font.Style = []
    Lines.Strings = (
      'Memo1')
    ParentFont = False
    TabOrder = 0
    ExplicitLeft = 32
    ExplicitTop = 16
    ExplicitWidth = 185
    ExplicitHeight = 89
  end
  object MainMenu1: TMainMenu
    Left = 592
    Top = 8
    object Function1: TMenuItem
      Caption = 'Function'
      object Sin1: TMenuItem
        Caption = 'Sin'
      end
      object N1: TMenuItem
        Caption = 'Cos'
      end
      object Cos1: TMenuItem
        Caption = 'Exp'
      end
      object Ln1: TMenuItem
        Caption = 'Ln'
      end
    end
    object Interval1: TMenuItem
      Caption = 'Interval'
      object Set1: TMenuItem
        Caption = 'Set'#8230
        OnClick = Set1Click
      end
    end
    object Compute1: TMenuItem
      Caption = 'Compute'
      object abulate1: TMenuItem
        Caption = 'Tabulate'
        OnClick = Tabulate1Click
      end
      object SimpsonIntegral1: TMenuItem
        Caption = 'Simpson Integral'
        OnClick = SimpsonIntegral1Click
      end
    end
  end
end
