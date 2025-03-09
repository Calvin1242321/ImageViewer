//---------------------------------------------------------------------------

#include <fmx.h>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
namespace fullScope {

	struct ViewMode
	{
		int row;
		int column;
	};
	int PANELSIZE_H = 900;
	int PANELSIZE_W = 1350;
	std::vector<TImage*> pics;
	std::vector<String> pathes;
	std::vector<struct ViewMode> viewmodes;
	int imgIndex = 0;
}

void __fastcall TForm1::TBtnLoadingImageClick(TObject *Sender)
{
	if(!OpenDialog1->Execute()){
		return;
	}

	int imagesShowRow = fullScope::viewmodes[ComboBox1->ItemIndex].row;
	int imagesShowColumn = fullScope::viewmodes[ComboBox1->ItemIndex].column;

	int imagesShows = imagesShowRow*imagesShowColumn;
	fullScope::pathes.clear();

	for(int i = 0; i < OpenDialog1->Files->Count;i++){
		 fullScope::pathes.push_back(OpenDialog1->Files->Strings[i]);
	}

	for(int i = 0;i < fullScope::pics.size();i++){
		 delete fullScope::pics[i];
	}
	fullScope::pics.clear();
	fullScope::imgIndex = 0;
	for(int i = 0, j = 0; i < imagesShows;i++, j++){
		 if(j >= imagesShows)   break;
		 TImage *ti = new TImage(Form1);
		 ti->Parent = Panel1;

		 if(fullScope::pathes.size() > i){
			ti->Bitmap->LoadFromFile(fullScope::pathes[i]);
		 }

		 ti->Width = std::min((fullScope::PANELSIZE_H/imagesShowRow),(fullScope::PANELSIZE_W/imagesShowColumn)) - 5;
		 ti->Height = ti->Width;

		 int marginLeft = ((fullScope::PANELSIZE_W - (ti->Height*imagesShowColumn)) / (imagesShowColumn+1));
		 int marginTop = ((fullScope::PANELSIZE_H - (ti->Height*imagesShowRow)) / (imagesShowRow+1));
		 ti->Position->X = marginLeft + (ti->Height + marginLeft) * (i %imagesShowColumn);
		 ti->Position->Y = marginTop+(ti->Height + marginTop) * (i /imagesShowColumn);
		 fullScope::pics.push_back(ti);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TBtnChangeDisplayModeClick(TObject *Sender)
{
	int imagesShowRow = fullScope::viewmodes[ComboBox1->ItemIndex].row;
	int imagesShowColumn = fullScope::viewmodes[ComboBox1->ItemIndex].column;

	int imagesShows = imagesShowRow*imagesShowColumn;

	fullScope::imgIndex = 0;

	for(int i = 0;i < fullScope::pics.size();i++){
		 delete fullScope::pics[i];
	}
	fullScope::pics.clear();

	for(int i = 0, j = 0; i < imagesShows;i++, j++){
		 if(j >= imagesShows)   break;
		 TImage *ti = new TImage(Form1);
		 ti->Parent = Panel1;

		 if(fullScope::pathes.size() > i){
			ti->Bitmap->LoadFromFile(fullScope::pathes[i]);
		 }

		 ti->Width = std::min((fullScope::PANELSIZE_H/imagesShowRow),(fullScope::PANELSIZE_W/imagesShowColumn)) - 5;
		 ti->Height = ti->Width;

		 int marginLeft = ((fullScope::PANELSIZE_W - (ti->Height*imagesShowColumn)) / (imagesShowColumn+1));
		 int marginTop = ((fullScope::PANELSIZE_H - (ti->Height*imagesShowRow)) / (imagesShowRow+1));
		 ti->Position->X = marginLeft + (ti->Height + marginLeft) * (i %imagesShowColumn);
		 ti->Position->Y = marginTop + (ti->Height + marginTop) * (i /imagesShowColumn);
		 fullScope::pics.push_back(ti);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TBtnNextPageClick(TObject *Sender)
{
	int imagesShowRow = fullScope::viewmodes[ComboBox1->ItemIndex].row;
	int imagesShowColumn = fullScope::viewmodes[ComboBox1->ItemIndex].column;

	int imagesShows = imagesShowRow*imagesShowColumn;

	if(fullScope::pathes.size() <= ((fullScope::imgIndex / imagesShows)+1) * imagesShows){
		return;
	}

	fullScope::imgIndex += imagesShows;

	for(int i = 0;i < imagesShows;i++){
		fullScope::pics[i]->Visible = false;
	}

	for(int i = fullScope::imgIndex, j = 0;i < fullScope::pathes.size();i++, j++){
		if(j >= imagesShows)   break;
		if(fullScope::pathes.size() > i){
			fullScope::pics[j]->Bitmap->LoadFromFile(fullScope::pathes[i]);
			fullScope::pics[j]->Visible = true;
		}

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TBtnPerviousPageClick(TObject *Sender)
{
	int imagesShowRow = fullScope::viewmodes[ComboBox1->ItemIndex].row;
	int imagesShowColumn = fullScope::viewmodes[ComboBox1->ItemIndex].column;

	int imagesShows = imagesShowRow*imagesShowColumn;

	if(fullScope::imgIndex == 0){
		return;
	}

	fullScope::imgIndex -= imagesShows;

	for(int i = 0;i < imagesShows;i++){
		fullScope::pics[i]->Visible = false;
	}

	for(int i = fullScope::imgIndex, j = 0;i < fullScope::pathes.size();i++, j++){
		if(j >= imagesShows)   break;
		if(fullScope::pathes.size() > i){
			fullScope::pics[j]->Bitmap->LoadFromFile(fullScope::pathes[i]);
			fullScope::pics[j]->Visible = true;
		}

	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++){
			fullScope::ViewMode temp;
			temp.row = i + 1;
			temp.column = j+1;
			fullScope::viewmodes.push_back(temp);
		}
	}
	fullScope::ViewMode temp;
	temp.row = 5;
	temp.column = 5;
	fullScope::viewmodes.push_back(temp);
}
//---------------------------------------------------------------------------

