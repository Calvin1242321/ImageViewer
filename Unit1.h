//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *TBtnLoadingImage;
	TOpenDialog *OpenDialog1;
	TButton *TBtnNextPage;
	TButton *TBtnChangeDisplayMode;
	TImage *Image1;
	TComboBox *ComboBox1;
	TButton *TBtnPerviousPage;
	void __fastcall TBtnLoadingImageClick(TObject *Sender);
	void __fastcall TBtnChangeDisplayModeClick(TObject *Sender);
	void __fastcall TBtnNextPageClick(TObject *Sender);
	void __fastcall TBtnPerviousPageClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
