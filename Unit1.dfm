object VakuumatorForm: TVakuumatorForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1042#1072#1082#1091#1091#1084#1072#1090#1086#1088
  ClientHeight = 600
  ClientWidth = 600
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 100
    Height = 100
    Cursor = crNo
    ParentShowHint = False
    ShowHint = False
    Visible = False
    OnClick = Image1Click
  end
  object Label10: TLabel
    Left = 305
    Top = 34
    Width = 55
    Height = 70
    Alignment = taCenter
    AutoSize = False
    BiDiMode = bdLeftToRight
    Caption = #1043#1072#1079#1086'- '#1086#1093#1083#1072'- '#1076#1080#1090#1077#1083#1100
    Color = clWhite
    ParentBiDiMode = False
    ParentColor = False
    Transparent = False
    Layout = tlCenter
    WordWrap = True
  end
  object Label11: TLabel
    Left = 53
    Top = 85
    Width = 137
    Height = 138
    Alignment = taCenter
    AutoSize = False
    BiDiMode = bdLeftToRight
    Color = clWhite
    ParentBiDiMode = False
    ParentColor = False
    Transparent = False
    Layout = tlCenter
    WordWrap = True
  end
  object Button3: TButton
    Left = 264
    Top = 231
    Width = 75
    Height = 25
    Caption = #1047#1072#1087#1091#1089#1082
    TabOrder = 2
    OnClick = Button3Click
  end
  object GroupBox1: TGroupBox
    Left = 303
    Top = 262
    Width = 289
    Height = 130
    Caption = #1042#1086#1076#1086#1086#1093#1083#1072#1078#1076#1077#1085#1080#1077' '#1075#1072#1079#1086#1086#1093#1083#1072#1076#1080#1090#1077#1083#1103
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 56
      Height = 13
      Caption = 'T'#1074#1093' ('#1057') = 0'
    end
    object Label2: TLabel
      Left = 16
      Top = 30
      Width = 64
      Height = 13
      Caption = 'T'#1074#1099#1093' ('#1057') = 0'
    end
    object Label3: TLabel
      Left = 16
      Top = 68
      Width = 50
      Height = 13
      Caption = 'P ('#1055#1072') = 0'
    end
    object Label4: TLabel
      Left = 16
      Top = 87
      Width = 79
      Height = 13
      Caption = #1050#1083#1072#1087#1072#1085' (%) = 0'
    end
    object Label5: TLabel
      Left = 16
      Top = 49
      Width = 67
      Height = 13
      Caption = 'T'#1088#1072#1079#1085' ('#1057') = 0'
    end
    object TrackBar1: TTrackBar
      Left = 8
      Top = 106
      Width = 129
      Height = 18
      Enabled = False
      Max = 100
      ParentShowHint = False
      PageSize = 10
      Frequency = 5
      ShowHint = False
      ShowSelRange = False
      TabOrder = 0
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = TrackBar1Change
    end
    object CheckBox1: TCheckBox
      Left = 143
      Top = 106
      Width = 145
      Height = 18
      Caption = #1040#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080#1081' '#1088#1077#1078#1080#1084
      Checked = True
      State = cbChecked
      TabOrder = 1
      OnClick = CheckBox1Click
    end
    object LabeledEdit1: TLabeledEdit
      Left = 108
      Top = 73
      Width = 94
      Height = 21
      EditLabel.Width = 94
      EditLabel.Height = 13
      EditLabel.Caption = #1057#1080#1084#1091#1083#1103#1094#1080#1103' T'#1074#1093' ('#1057')'
      TabOrder = 2
      Text = '23'
      OnKeyPress = LabeledEdit1KeyPress
    end
    object Button1: TButton
      Left = 208
      Top = 36
      Width = 78
      Height = 61
      Caption = #1055#1086#1076#1090#1074#1077#1088#1076#1080#1090#1100' '#1074#1074#1086#1076' T'#1074#1093' '#1080' '#1079#1072#1076#1072#1085#1085#1086#1081' '#1088#1072#1079#1085#1080#1094#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      WordWrap = True
      OnClick = Button1Click
    end
    object LabeledEdit2: TLabeledEdit
      Left = 108
      Top = 34
      Width = 94
      Height = 21
      EditLabel.Width = 170
      EditLabel.Height = 13
      EditLabel.Caption = #1047#1072#1076#1072#1085#1085#1072#1103' '#1088#1072#1079#1085#1080#1094#1072' T'#1074#1093' '#1080' '#1058#1074#1099#1093' ('#1057')'
      TabOrder = 4
      Text = '50'
      OnKeyPress = LabeledEdit2KeyPress
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 262
    Width = 289
    Height = 130
    Caption = #1042#1072#1082#1091#1091#1084#1072#1090#1086#1088
    TabOrder = 1
    object Label6: TLabel
      Left = 16
      Top = 18
      Width = 102
      Height = 13
      Caption = #1056' ('#1055#1072') = 000000.000'
    end
    object Label7: TLabel
      Left = 124
      Top = 18
      Width = 122
      Height = 13
      Caption = #1050#1083#1072#1087#1072#1085' '#1056' (%) = 000.000'
    end
    object Label8: TLabel
      Left = 208
      Top = 33
      Width = 59
      Height = 13
      Caption = 'F ('#1084'3/'#1095') = 0'
    end
    object Label9: TLabel
      Left = 176
      Top = 85
      Width = 100
      Height = 13
      Caption = #1050#1083#1072#1087#1072#1085' F (%) = 100'
    end
    object TrackBar2: TTrackBar
      Left = 72
      Top = 37
      Width = 122
      Height = 18
      Enabled = False
      Max = 1000
      ParentShowHint = False
      PageSize = 10
      Frequency = 5
      ShowHint = False
      ShowSelRange = False
      TabOrder = 0
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = TrackBar2Change
    end
    object TrackBar3: TTrackBar
      Left = 72
      Top = 61
      Width = 122
      Height = 18
      Enabled = False
      Max = 1000
      ParentShowHint = False
      PageSize = 10
      Frequency = 5
      ShowHint = False
      ShowSelRange = False
      TabOrder = 1
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = TrackBar3Change
    end
    object LabeledEdit3: TLabeledEdit
      Left = 16
      Top = 53
      Width = 53
      Height = 21
      EditLabel.Width = 45
      EditLabel.Height = 13
      EditLabel.Caption = 'P '#1079#1076' ('#1055#1072')'
      Enabled = False
      TabOrder = 2
      Text = '101325'
      OnKeyPress = LabeledEdit3KeyPress
    end
    object TrackBar4: TTrackBar
      Left = 176
      Top = 104
      Width = 100
      Height = 18
      Enabled = False
      Max = 100
      ParentShowHint = False
      PageSize = 10
      Frequency = 5
      ShowHint = False
      ShowSelRange = False
      TabOrder = 3
      ThumbLength = 15
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = TrackBar4Change
    end
    object LabeledEdit4: TLabeledEdit
      Left = 208
      Top = 63
      Width = 59
      Height = 21
      EditLabel.Width = 54
      EditLabel.Height = 13
      EditLabel.Caption = 'F '#1079#1076' ('#1084'3/'#1095')'
      Enabled = False
      TabOrder = 4
      Text = '90'
      OnKeyPress = LabeledEdit4KeyPress
    end
    object CheckBox2: TCheckBox
      Left = 16
      Top = 85
      Width = 89
      Height = 18
      Caption = #1040#1074#1090#1086' '#1088#1077#1078#1080#1084' '#1056
      Checked = True
      Enabled = False
      State = cbChecked
      TabOrder = 5
      OnClick = CheckBox2Click
    end
    object CheckBox3: TCheckBox
      Left = 16
      Top = 104
      Width = 89
      Height = 18
      Caption = #1040#1074#1090#1086' '#1088#1077#1078#1080#1084' F'
      Checked = True
      Enabled = False
      State = cbChecked
      TabOrder = 6
      OnClick = CheckBox3Click
    end
    object Button2: TButton
      Left = 111
      Top = 85
      Width = 59
      Height = 19
      Caption = #1042#1074#1086#1076' '#1079#1076
      Enabled = False
      TabOrder = 7
      OnClick = Button2Click
    end
    object CheckBox4: TCheckBox
      Left = 111
      Top = 104
      Width = 65
      Height = 18
      Caption = #1040#1074#1090#1086' '#1047#1044
      Checked = True
      State = cbChecked
      TabOrder = 8
      OnClick = CheckBox4Click
    end
  end
  object Chart1: TChart
    Left = 8
    Top = 398
    Width = 289
    Height = 203
    Legend.Visible = False
    Title.Font.Color = clBlack
    Title.Text.Strings = (
      #1043#1088#1072#1092#1080#1082' '#1076#1072#1074#1083#1077#1085#1080#1103' '#1074' '#1074#1072#1082#1091#1091#1084#1072#1090#1086#1088#1077)
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.LabelsFormat.Font.Height = -7
    BottomAxis.Title.Caption = #1042#1088#1077#1084#1103' ('#1089#1077#1082')'
    BottomAxis.Title.Font.Height = -7
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.LabelsFormat.Font.Height = -7
    LeftAxis.Maximum = 101325.000000000000000000
    LeftAxis.Title.Caption = #1044#1072#1074#1083#1077#1085#1080#1077' ('#1055#1072')'
    LeftAxis.Title.Font.Height = -7
    View3D = False
    TabOrder = 3
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 14
    object Series1: TLineSeries
      SeriesColor = 234
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object Chart2: TChart
    Left = 303
    Top = 398
    Width = 289
    Height = 203
    Legend.Visible = False
    Title.Font.Color = clBlack
    Title.Text.Strings = (
      #1043#1088#1072#1092#1080#1082' '#1088#1072#1089#1093#1086#1076#1072' '#1085#1077#1081#1090#1088#1072#1083#1100#1085#1086#1075#1086' '#1075#1072#1079#1072)
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.LabelsFormat.Font.Height = -7
    BottomAxis.Title.Caption = #1042#1088#1077#1084#1103' ('#1089#1077#1082')'
    BottomAxis.Title.Font.Height = -7
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.LabelsFormat.Font.Height = -7
    LeftAxis.Maximum = 100.000000000000000000
    LeftAxis.Title.Caption = #1056#1072#1089#1093#1086#1076' '#1075#1072#1079#1072' ('#1084'3/'#1089')'
    LeftAxis.Title.Font.Height = -7
    View3D = False
    TabOrder = 4
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 14
    object LineSeries1: TLineSeries
      SeriesColor = 16711696
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 560
    Top = 232
  end
end
