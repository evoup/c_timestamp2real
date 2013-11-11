{ 这份源代码文件已被未注册的SourceFormatX格式化过 }
{ 如果您想不再添加此类信息，请您注册这个共享软件  }
{ 更多相关信息请访问网站: http://cn.textrush.com  }

unit convert;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls, psvWebLabel, psvBasiclbl;

type
  TForm1 = class(TForm)
    GroupBox2: TGroupBox;
    Label11: TLabel;
    Label16: TLabel;
    Label17: TLabel;
    Label18: TLabel;
    Label19: TLabel;
    Label20: TLabel;
    Label21: TLabel;
    Button3: TButton;
    DateTimePicker2: TDateTimePicker;
    Edit12: TEdit;
    Edit17: TEdit;
    Edit18: TEdit;
    Edit19: TEdit;
    Edit20: TEdit;
    Edit21: TEdit;
    Edit22: TEdit;
    GroupBox3: TGroupBox;
    Label22: TLabel;
    Label23: TLabel;
    Label24: TLabel;
    Label25: TLabel;
    Label26: TLabel;
    Label27: TLabel;
    Label28: TLabel;
    Label29: TLabel;
    Edit23: TEdit;
    Edit24: TEdit;
    Edit25: TEdit;
    Edit26: TEdit;
    Edit27: TEdit;
    Edit28: TEdit;
    Edit29: TEdit;
    Button2: TButton;
    Edit30: TEdit;
    Button1: TButton;
    Edit1: TEdit;
    UpDown1: TUpDown;
    Label1: TLabel;
    psvWebLabel1: TpsvWebLabel;
    psvWebLabel2: TpsvWebLabel;
    Edit2: TEdit;
    UpDown2: TUpDown;
    Label2: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
begin
  Application.Terminate;
end;

procedure TForm1.Button2Click(Sender: TObject);
var
  Result: Tdatetime;
begin
  Result := EncodeDate(1970, 1, 1) + ((StrToFloat(edit26.Text) +
    (StrToFloat(edit2.Text) * 3600)) / 86400); {86400=No. of secs. per day}

  edit23.Text := FormatDateTime('d', Result);
  edit24.Text := FormatDateTime('m', Result);
  edit25.Text := FormatDateTime('yyyy', Result);
  edit27.Text := FormatDateTime('h', Result);
  edit28.Text := FormatDateTime('n', Result);
  edit29.Text := FormatDateTime('s', Result);
  edit30.Text := DateTimeToStr(Result);
  form1.ActiveControl := edit30;
end;


procedure TForm1.Button3Click(Sender: TObject);
var
  x, y: Extended;
begin
  edit12.Text := FormatDateTime('d', datetimepicker2.Date);
  edit17.Text := FormatDateTime('m', datetimepicker2.Date);
  edit18.Text := FormatDateTime('yyyy', datetimepicker2.Date);
  x := (EncodeDate(StrToInt(edit18.Text), StrToInt(edit17.Text),
    StrToInt(edit12.Text)) - EncodeDate(1970, 1, 1)) * 86400;
  y := (StrToInt(edit20.Text) * 3600) + (StrToInt(edit21.Text) * 60) +
    StrToInt(edit22.Text);
  x := x + y - (StrToFloat(edit1.Text) * 3600);
  edit19.Text := FloatToStr(x);
  form1.ActiveControl := edit19;
end;

procedure TForm1.FormCreate(Sender: TObject);
var
  present: Tdatetime;
begin
  present := Now;
  DateTimePicker2.Date := present;
  edit20.Text := FormatDateTime('h', present);
  edit21.Text := FormatDateTime('n', present);
  edit22.Text := FormatDateTime('s', present);
end;

end.
