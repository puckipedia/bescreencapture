#ifndef __OUTPUTVIEW_H
#define __OUTPUTVIEW_H

#include <MediaDefs.h>
#include <MediaFormats.h>
#include <Path.h>
#include <Size.h>
#include <View.h>

class BButton;
class BCheckBox;
class BMenu;
class BMenuField;
class BOptionPopUp;
class BRadioButton;
class BTextControl;
class Controller;
class PreviewView;
class OutputView : public BView {
public:	
	OutputView(Controller *controller);

	virtual void AttachedToWindow();
	virtual void MessageReceived(BMessage *message);
	
	void UpdateSettings();
	
	BPath OutputFileName() const;
	media_format_family FormatFamily() const;
	
	bool MinimizeOnStart() const;
		
	void UpdatePreviewFromSettings();
		
	virtual	BSize	MinSize();		
private:
	Controller *fController;
	BTextControl *fFileName;	
	BOptionPopUp *fOutputFileType;
	
	BMenuField *fCodecMenu;
	BCheckBox *fMinimizeOnStart;
	
	BButton *fSelectArea;
	BRadioButton *fWholeScreen;
	BRadioButton *fCustomArea;
	PreviewView *fRectView;
	BButton* fFilePanelButton;
			
	void _RebuildCodecsMenu();

	void _UpdatePreview(BMessage* message);
	
	static BMenuItem *CreateCodecMenuItem(const media_codec_info &codec);
	
	
};


#endif
