// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// _Application wrapper class

class _Application : public COleDispatchDriver
{
public:
	_Application() {}		// Calls COleDispatchDriver default constructor
	_Application(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_Application(const _Application& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	CString GetName();
	LPDISPATCH GetDocuments();
	LPDISPATCH GetWindows();
	LPDISPATCH GetActiveDocument();
	LPDISPATCH GetActiveWindow();
	LPDISPATCH GetSelection();
	LPDISPATCH GetWordBasic();
	LPDISPATCH GetRecentFiles();
	LPDISPATCH GetNormalTemplate();
	LPDISPATCH GetSystem();
	LPDISPATCH GetAutoCorrect();
	LPDISPATCH GetFontNames();
	LPDISPATCH GetLandscapeFontNames();
	LPDISPATCH GetPortraitFontNames();
	LPDISPATCH GetLanguages();
	LPDISPATCH GetAssistant();
	LPDISPATCH GetBrowser();
	LPDISPATCH GetFileConverters();
	LPDISPATCH GetMailingLabel();
	LPDISPATCH GetDialogs();
	LPDISPATCH GetCaptionLabels();
	LPDISPATCH GetAutoCaptions();
	LPDISPATCH GetAddIns();
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	CString GetVersion();
	BOOL GetScreenUpdating();
	void SetScreenUpdating(BOOL bNewValue);
	BOOL GetPrintPreview();
	void SetPrintPreview(BOOL bNewValue);
	LPDISPATCH GetTasks();
	BOOL GetDisplayStatusBar();
	void SetDisplayStatusBar(BOOL bNewValue);
	BOOL GetSpecialMode();
	long GetUsableWidth();
	long GetUsableHeight();
	BOOL GetMathCoprocessorAvailable();
	BOOL GetMouseAvailable();
	VARIANT GetInternational(long Index);
	CString GetBuild();
	BOOL GetCapsLock();
	BOOL GetNumLock();
	CString GetUserName_();
	void SetUserName(LPCTSTR lpszNewValue);
	CString GetUserInitials();
	void SetUserInitials(LPCTSTR lpszNewValue);
	CString GetUserAddress();
	void SetUserAddress(LPCTSTR lpszNewValue);
	LPDISPATCH GetMacroContainer();
	BOOL GetDisplayRecentFiles();
	void SetDisplayRecentFiles(BOOL bNewValue);
	LPDISPATCH GetCommandBars();
	LPDISPATCH GetSynonymInfo(LPCTSTR Word, VARIANT* LanguageID);
	LPDISPATCH GetVbe();
	CString GetDefaultSaveFormat();
	void SetDefaultSaveFormat(LPCTSTR lpszNewValue);
	LPDISPATCH GetListGalleries();
	CString GetActivePrinter();
	void SetActivePrinter(LPCTSTR lpszNewValue);
	LPDISPATCH GetTemplates();
	LPDISPATCH GetCustomizationContext();
	void SetCustomizationContext(LPDISPATCH newValue);
	LPDISPATCH GetKeyBindings();
	LPDISPATCH GetKeysBoundTo(long KeyCategory, LPCTSTR Command, VARIANT* CommandParameter);
	LPDISPATCH GetFindKey(long KeyCode, VARIANT* KeyCode2);
	CString GetCaption();
	void SetCaption(LPCTSTR lpszNewValue);
	CString GetPath();
	BOOL GetDisplayScrollBars();
	void SetDisplayScrollBars(BOOL bNewValue);
	CString GetStartupPath();
	void SetStartupPath(LPCTSTR lpszNewValue);
	long GetBackgroundSavingStatus();
	long GetBackgroundPrintingStatus();
	long GetLeft();
	void SetLeft(long nNewValue);
	long GetTop();
	void SetTop(long nNewValue);
	long GetWidth();
	void SetWidth(long nNewValue);
	long GetHeight();
	void SetHeight(long nNewValue);
	long GetWindowState();
	void SetWindowState(long nNewValue);
	BOOL GetDisplayAutoCompleteTips();
	void SetDisplayAutoCompleteTips(BOOL bNewValue);
	LPDISPATCH GetOptions();
	long GetDisplayAlerts();
	void SetDisplayAlerts(long nNewValue);
	LPDISPATCH GetCustomDictionaries();
	CString GetPathSeparator();
	void SetStatusBar(LPCTSTR lpszNewValue);
	BOOL GetMAPIAvailable();
	BOOL GetDisplayScreenTips();
	void SetDisplayScreenTips(BOOL bNewValue);
	long GetEnableCancelKey();
	void SetEnableCancelKey(long nNewValue);
	BOOL GetUserControl();
	LPDISPATCH GetFileSearch();
	long GetMailSystem();
	CString GetDefaultTableSeparator();
	void SetDefaultTableSeparator(LPCTSTR lpszNewValue);
	BOOL GetShowVisualBasicEditor();
	void SetShowVisualBasicEditor(BOOL bNewValue);
	CString GetBrowseExtraFileTypes();
	void SetBrowseExtraFileTypes(LPCTSTR lpszNewValue);
	BOOL GetIsObjectValid(LPDISPATCH Object);
	LPDISPATCH GetHangulHanjaDictionaries();
	LPDISPATCH GetMailMessage();
	BOOL GetFocusInMailHeader();
	void Quit(VARIANT* SaveChanges, VARIANT* OriginalFormat, VARIANT* RouteDocument);
	void ScreenRefresh();
	void LookupNameProperties(LPCTSTR Name);
	void SubstituteFont(LPCTSTR UnavailableFont, LPCTSTR SubstituteFont);
	BOOL Repeat(VARIANT* Times);
	void DDEExecute(long Channel, LPCTSTR Command);
	long DDEInitiate(LPCTSTR App, LPCTSTR Topic);
	void DDEPoke(long Channel, LPCTSTR Item, LPCTSTR Data);
	CString DDERequest(long Channel, LPCTSTR Item);
	void DDETerminate(long Channel);
	void DDETerminateAll();
	long BuildKeyCode(long Arg1, VARIANT* Arg2, VARIANT* Arg3, VARIANT* Arg4);
	CString KeyString(long KeyCode, VARIANT* KeyCode2);
	void OrganizerCopy(LPCTSTR Source, LPCTSTR Destination, LPCTSTR Name, long Object);
	void OrganizerDelete(LPCTSTR Source, LPCTSTR Name, long Object);
	void OrganizerRename(LPCTSTR Source, LPCTSTR Name, LPCTSTR NewName, long Object);
	// method 'AddAddress' not emitted because of invalid return type or parameter type
	CString GetAddress(VARIANT* Name, VARIANT* AddressProperties, VARIANT* UseAutoText, VARIANT* DisplaySelectDialog, VARIANT* SelectDialog, VARIANT* CheckNamesDialog, VARIANT* RecentAddressesChoice, VARIANT* UpdateRecentAddresses);
	BOOL CheckGrammar(LPCTSTR String);
	BOOL CheckSpelling(LPCTSTR Word, VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, 
		VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10);
	void ResetIgnoreAll();
	LPDISPATCH GetSpellingSuggestions(LPCTSTR Word, VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* SuggestionMode, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, 
		VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10);
	void GoBack();
	void Help(VARIANT* HelpType);
	void AutomaticChange();
	void ShowMe();
	void HelpTool();
	LPDISPATCH NewWindow();
	void ListCommands(BOOL ListAllCommands);
	void ShowClipboard();
	void OnTime(VARIANT* When, LPCTSTR Name, VARIANT* Tolerance);
	void NextLetter();
	short MountVolume(LPCTSTR Zone, LPCTSTR Server, LPCTSTR Volume, VARIANT* User, VARIANT* UserPassword, VARIANT* VolumePassword);
	CString CleanString(LPCTSTR String);
	void SendFax();
	void ChangeFileOpenDirectory(LPCTSTR Path);
	void GoForward();
	void Move(long Left, long Top);
	void Resize(long Width, long Height);
	float InchesToPoints(float Inches);
	float CentimetersToPoints(float Centimeters);
	float MillimetersToPoints(float Millimeters);
	float PicasToPoints(float Picas);
	float LinesToPoints(float Lines);
	float PointsToInches(float Points);
	float PointsToCentimeters(float Points);
	float PointsToMillimeters(float Points);
	float PointsToPicas(float Points);
	float PointsToLines(float Points);
	void Activate();
	float PointsToPixels(float Points, VARIANT* fVertical);
	float PixelsToPoints(float Pixels, VARIANT* fVertical);
	void KeyboardLatin();
	void KeyboardBidi();
	void ToggleKeyboard();
	long Keyboard(long LangId);
	CString ProductCode();
	LPDISPATCH DefaultWebOptions();
	void SetDefaultTheme(LPCTSTR Name, long DocumentType);
	CString GetDefaultTheme(long DocumentType);
	LPDISPATCH GetEmailOptions();
	long GetLanguage();
	LPDISPATCH GetCOMAddIns();
	BOOL GetCheckLanguage();
	void SetCheckLanguage(BOOL bNewValue);
	LPDISPATCH GetLanguageSettings();
	LPDISPATCH GetAnswerWizard();
	long GetFeatureInstall();
	void SetFeatureInstall(long nNewValue);
	void PrintOut(VARIANT* Background, VARIANT* Append, VARIANT* Range, VARIANT* OutputFileName, VARIANT* From, VARIANT* To, VARIANT* Item, VARIANT* Copies, VARIANT* Pages, VARIANT* PageType, VARIANT* PrintToFile, VARIANT* Collate, 
		VARIANT* FileName, VARIANT* ActivePrinterMacGX, VARIANT* ManualDuplexPrint, VARIANT* PrintZoomColumn, VARIANT* PrintZoomRow, VARIANT* PrintZoomPaperWidth, VARIANT* PrintZoomPaperHeight);
	VARIANT Run(LPCTSTR MacroName, VARIANT* varg1, VARIANT* varg2, VARIANT* varg3, VARIANT* varg4, VARIANT* varg5, VARIANT* varg6, VARIANT* varg7, VARIANT* varg8, VARIANT* varg9, VARIANT* varg10, VARIANT* varg11, VARIANT* varg12, VARIANT* varg13, 
		VARIANT* varg14, VARIANT* varg15, VARIANT* varg16, VARIANT* varg17, VARIANT* varg18, VARIANT* varg19, VARIANT* varg20, VARIANT* varg21, VARIANT* varg22, VARIANT* varg23, VARIANT* varg24, VARIANT* varg25, VARIANT* varg26, VARIANT* varg27, 
		VARIANT* varg28, VARIANT* varg29, VARIANT* varg30);
};
/////////////////////////////////////////////////////////////////////////////
// Documents wrapper class

class Documents : public COleDispatchDriver
{
public:
	Documents() {}		// Calls COleDispatchDriver default constructor
	Documents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Documents(const Documents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Item(VARIANT* Index);
	void Close(VARIANT* SaveChanges, VARIANT* OriginalFormat, VARIANT* RouteDocument);
	void Save(VARIANT* NoPrompt, VARIANT* OriginalFormat);
	LPDISPATCH Add(VARIANT* Template, VARIANT* NewTemplate, VARIANT* DocumentType, VARIANT* Visible);
	LPDISPATCH Open(VARIANT* FileName, VARIANT* ConfirmConversions, VARIANT* ReadOnly, VARIANT* AddToRecentFiles, VARIANT* PasswordDocument, VARIANT* PasswordTemplate, VARIANT* Revert, VARIANT* WritePasswordDocument, 
		VARIANT* WritePasswordTemplate, VARIANT* Format, VARIANT* Encoding, VARIANT* Visible);
};
/////////////////////////////////////////////////////////////////////////////
// _Document wrapper class

class _Document : public COleDispatchDriver
{
public:
	_Document() {}		// Calls COleDispatchDriver default constructor
	_Document(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_Document(const _Document& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetName();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetBuiltInDocumentProperties();
	LPDISPATCH GetCustomDocumentProperties();
	CString GetPath();
	LPDISPATCH GetBookmarks();
	LPDISPATCH GetTables();
	LPDISPATCH GetFootnotes();
	LPDISPATCH GetEndnotes();
	LPDISPATCH GetComments();
	long GetType();
	BOOL GetAutoHyphenation();
	void SetAutoHyphenation(BOOL bNewValue);
	BOOL GetHyphenateCaps();
	void SetHyphenateCaps(BOOL bNewValue);
	long GetHyphenationZone();
	void SetHyphenationZone(long nNewValue);
	long GetConsecutiveHyphensLimit();
	void SetConsecutiveHyphensLimit(long nNewValue);
	LPDISPATCH GetSections();
	LPDISPATCH GetParagraphs();
	LPDISPATCH GetWords();
	LPDISPATCH GetSentences();
	LPDISPATCH GetCharacters();
	LPDISPATCH GetFields();
	LPDISPATCH GetFormFields();
	LPDISPATCH GetStyles();
	LPDISPATCH GetFrames();
	LPDISPATCH GetTablesOfFigures();
	LPDISPATCH GetVariables();
	LPDISPATCH GetMailMerge();
	LPDISPATCH GetEnvelope();
	CString GetFullName();
	LPDISPATCH GetRevisions();
	LPDISPATCH GetTablesOfContents();
	LPDISPATCH GetTablesOfAuthorities();
	LPDISPATCH GetPageSetup();
	void SetPageSetup(LPDISPATCH newValue);
	LPDISPATCH GetWindows();
	BOOL GetHasRoutingSlip();
	void SetHasRoutingSlip(BOOL bNewValue);
	LPDISPATCH GetRoutingSlip();
	BOOL GetRouted();
	LPDISPATCH GetTablesOfAuthoritiesCategories();
	LPDISPATCH GetIndexes();
	BOOL GetSaved();
	void SetSaved(BOOL bNewValue);
	LPDISPATCH GetContent();
	LPDISPATCH GetActiveWindow();
	long GetKind();
	void SetKind(long nNewValue);
	BOOL GetReadOnly();
	LPDISPATCH GetSubdocuments();
	BOOL GetIsMasterDocument();
	float GetDefaultTabStop();
	void SetDefaultTabStop(float newValue);
	BOOL GetEmbedTrueTypeFonts();
	void SetEmbedTrueTypeFonts(BOOL bNewValue);
	BOOL GetSaveFormsData();
	void SetSaveFormsData(BOOL bNewValue);
	BOOL GetReadOnlyRecommended();
	void SetReadOnlyRecommended(BOOL bNewValue);
	BOOL GetSaveSubsetFonts();
	void SetSaveSubsetFonts(BOOL bNewValue);
	BOOL GetCompatibility(long Type);
	void SetCompatibility(long Type, BOOL bNewValue);
	LPDISPATCH GetStoryRanges();
	LPDISPATCH GetCommandBars();
	BOOL GetIsSubdocument();
	long GetSaveFormat();
	long GetProtectionType();
	LPDISPATCH GetHyperlinks();
	LPDISPATCH GetShapes();
	LPDISPATCH GetListTemplates();
	LPDISPATCH GetLists();
	BOOL GetUpdateStylesOnOpen();
	void SetUpdateStylesOnOpen(BOOL bNewValue);
	VARIANT GetAttachedTemplate();
	void SetAttachedTemplate(VARIANT* newValue);
	LPDISPATCH GetInlineShapes();
	LPDISPATCH GetBackground();
	void SetBackground(LPDISPATCH newValue);
	BOOL GetGrammarChecked();
	void SetGrammarChecked(BOOL bNewValue);
	BOOL GetSpellingChecked();
	void SetSpellingChecked(BOOL bNewValue);
	BOOL GetShowGrammaticalErrors();
	void SetShowGrammaticalErrors(BOOL bNewValue);
	BOOL GetShowSpellingErrors();
	void SetShowSpellingErrors(BOOL bNewValue);
	LPDISPATCH GetVersions();
	BOOL GetShowSummary();
	void SetShowSummary(BOOL bNewValue);
	long GetSummaryViewMode();
	void SetSummaryViewMode(long nNewValue);
	long GetSummaryLength();
	void SetSummaryLength(long nNewValue);
	BOOL GetPrintFractionalWidths();
	void SetPrintFractionalWidths(BOOL bNewValue);
	BOOL GetPrintPostScriptOverText();
	void SetPrintPostScriptOverText(BOOL bNewValue);
	LPDISPATCH GetContainer();
	BOOL GetPrintFormsData();
	void SetPrintFormsData(BOOL bNewValue);
	LPDISPATCH GetListParagraphs();
	void SetPassword(LPCTSTR lpszNewValue);
	void SetWritePassword(LPCTSTR lpszNewValue);
	BOOL GetHasPassword();
	BOOL GetWriteReserved();
	CString GetActiveWritingStyle(VARIANT* LanguageID);
	void SetActiveWritingStyle(VARIANT* LanguageID, LPCTSTR lpszNewValue);
	BOOL GetUserControl();
	void SetUserControl(BOOL bNewValue);
	BOOL GetHasMailer();
	void SetHasMailer(BOOL bNewValue);
	LPDISPATCH GetMailer();
	LPDISPATCH GetReadabilityStatistics();
	LPDISPATCH GetGrammaticalErrors();
	LPDISPATCH GetSpellingErrors();
	LPDISPATCH GetVBProject();
	BOOL GetFormsDesign();
	CString Get_CodeName();
	void Set_CodeName(LPCTSTR lpszNewValue);
	CString GetCodeName();
	BOOL GetSnapToGrid();
	void SetSnapToGrid(BOOL bNewValue);
	BOOL GetSnapToShapes();
	void SetSnapToShapes(BOOL bNewValue);
	float GetGridDistanceHorizontal();
	void SetGridDistanceHorizontal(float newValue);
	float GetGridDistanceVertical();
	void SetGridDistanceVertical(float newValue);
	float GetGridOriginHorizontal();
	void SetGridOriginHorizontal(float newValue);
	float GetGridOriginVertical();
	void SetGridOriginVertical(float newValue);
	long GetGridSpaceBetweenHorizontalLines();
	void SetGridSpaceBetweenHorizontalLines(long nNewValue);
	long GetGridSpaceBetweenVerticalLines();
	void SetGridSpaceBetweenVerticalLines(long nNewValue);
	BOOL GetGridOriginFromMargin();
	void SetGridOriginFromMargin(BOOL bNewValue);
	BOOL GetKerningByAlgorithm();
	void SetKerningByAlgorithm(BOOL bNewValue);
	long GetJustificationMode();
	void SetJustificationMode(long nNewValue);
	long GetFarEastLineBreakLevel();
	void SetFarEastLineBreakLevel(long nNewValue);
	CString GetNoLineBreakBefore();
	void SetNoLineBreakBefore(LPCTSTR lpszNewValue);
	CString GetNoLineBreakAfter();
	void SetNoLineBreakAfter(LPCTSTR lpszNewValue);
	BOOL GetTrackRevisions();
	void SetTrackRevisions(BOOL bNewValue);
	BOOL GetPrintRevisions();
	void SetPrintRevisions(BOOL bNewValue);
	BOOL GetShowRevisions();
	void SetShowRevisions(BOOL bNewValue);
	void Close(VARIANT* SaveChanges, VARIANT* OriginalFormat, VARIANT* RouteDocument);
	void SaveAs(VARIANT* FileName, VARIANT* FileFormat, VARIANT* LockComments, VARIANT* Password, VARIANT* AddToRecentFiles, VARIANT* WritePassword, VARIANT* ReadOnlyRecommended, VARIANT* EmbedTrueTypeFonts, VARIANT* SaveNativePictureFormat, 
		VARIANT* SaveFormsData, VARIANT* SaveAsAOCELetter);
	void Repaginate();
	void FitToPages();
	void ManualHyphenation();
	void Select();
	void DataForm();
	void Route();
	void Save();
	void SendMail();
	LPDISPATCH Range(VARIANT* Start, VARIANT* End);
	void RunAutoMacro(long Which);
	void Activate();
	void PrintPreview();
	LPDISPATCH GoTo(VARIANT* What, VARIANT* Which, VARIANT* Count, VARIANT* Name);
	BOOL Undo(VARIANT* Times);
	BOOL Redo(VARIANT* Times);
	long ComputeStatistics(long Statistic, VARIANT* IncludeFootnotesAndEndnotes);
	void MakeCompatibilityDefault();
	void Protect(long Type, VARIANT* NoReset, VARIANT* Password);
	void Unprotect(VARIANT* Password);
	void EditionOptions(long Type, long Option, LPCTSTR Name, VARIANT* Format);
	void RunLetterWizard(VARIANT* LetterContent, VARIANT* WizardMode);
	LPDISPATCH GetLetterContent();
	void SetLetterContent(VARIANT* LetterContent);
	void CopyStylesFromTemplate(LPCTSTR Template);
	void UpdateStyles();
	void CheckGrammar();
	void CheckSpelling(VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* AlwaysSuggest, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, 
		VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10);
	void FollowHyperlink(VARIANT* Address, VARIANT* SubAddress, VARIANT* NewWindow, VARIANT* AddHistory, VARIANT* ExtraInfo, VARIANT* Method, VARIANT* HeaderInfo);
	void AddToFavorites();
	void Reload();
	LPDISPATCH AutoSummarize(VARIANT* Length, VARIANT* Mode, VARIANT* UpdateProperties);
	void RemoveNumbers(VARIANT* NumberType);
	void ConvertNumbersToText(VARIANT* NumberType);
	long CountNumberedItems(VARIANT* NumberType, VARIANT* Level);
	void Post();
	void ToggleFormsDesign();
	void Compare(LPCTSTR Name);
	void UpdateSummaryProperties();
	VARIANT GetCrossReferenceItems(VARIANT* ReferenceType);
	void AutoFormat();
	void ViewCode();
	void ViewPropertyBrowser();
	void ForwardMailer();
	void Reply();
	void ReplyAll();
	void SendMailer(VARIANT* FileFormat, VARIANT* Priority);
	void UndoClear();
	void PresentIt();
	void SendFax(LPCTSTR Address, VARIANT* Subject);
	void Merge(LPCTSTR FileName);
	void ClosePrintPreview();
	void CheckConsistency();
	LPDISPATCH CreateLetterContent(LPCTSTR DateFormat, BOOL IncludeHeaderFooter, LPCTSTR PageDesign, long LetterStyle, BOOL Letterhead, long LetterheadLocation, float LetterheadSize, LPCTSTR RecipientName, LPCTSTR RecipientAddress, 
		LPCTSTR Salutation, long SalutationType, LPCTSTR RecipientReference, LPCTSTR MailingInstructions, LPCTSTR AttentionLine, LPCTSTR Subject, LPCTSTR CCList, LPCTSTR ReturnAddress, LPCTSTR SenderName, LPCTSTR Closing, LPCTSTR SenderCompany, 
		LPCTSTR SenderJobTitle, LPCTSTR SenderInitials, long EnclosureNumber, VARIANT* InfoBlock, VARIANT* RecipientCode, VARIANT* RecipientGender, VARIANT* ReturnAddressShortForm, VARIANT* SenderCity, VARIANT* SenderCode, VARIANT* SenderGender, 
		VARIANT* SenderReference);
	void AcceptAllRevisions();
	void RejectAllRevisions();
	void DetectLanguage();
	void ApplyTheme(LPCTSTR Name);
	void RemoveTheme();
	void WebPagePreview();
	void ReloadAs(long Encoding);
	CString GetActiveTheme();
	CString GetActiveThemeDisplayName();
	LPDISPATCH GetEmail();
	LPDISPATCH GetScripts();
	BOOL GetLanguageDetected();
	void SetLanguageDetected(BOOL bNewValue);
	long GetFarEastLineBreakLanguage();
	void SetFarEastLineBreakLanguage(long nNewValue);
	LPDISPATCH GetFrameset();
	VARIANT GetClickAndTypeParagraphStyle();
	void SetClickAndTypeParagraphStyle(VARIANT* newValue);
	LPDISPATCH GetHTMLProject();
	LPDISPATCH GetWebOptions();
	long GetOpenEncoding();
	long GetSaveEncoding();
	void SetSaveEncoding(long nNewValue);
	BOOL GetOptimizeForWord97();
	void SetOptimizeForWord97(BOOL bNewValue);
	BOOL GetVBASigned();
	void PrintOut(VARIANT* Background, VARIANT* Append, VARIANT* Range, VARIANT* OutputFileName, VARIANT* From, VARIANT* To, VARIANT* Item, VARIANT* Copies, VARIANT* Pages, VARIANT* PageType, VARIANT* PrintToFile, VARIANT* Collate, 
		VARIANT* ActivePrinterMacGX, VARIANT* ManualDuplexPrint, VARIANT* PrintZoomColumn, VARIANT* PrintZoomRow, VARIANT* PrintZoomPaperWidth, VARIANT* PrintZoomPaperHeight);
};
/////////////////////////////////////////////////////////////////////////////
// Range wrapper class

class Range : public COleDispatchDriver
{
public:
	Range() {}		// Calls COleDispatchDriver default constructor
	Range(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Range(const Range& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetText();
	void SetText(LPCTSTR lpszNewValue);
	LPDISPATCH GetFormattedText();
	void SetFormattedText(LPDISPATCH newValue);
	long GetStart();
	void SetStart(long nNewValue);
	long GetEnd();
	void SetEnd(long nNewValue);
	LPDISPATCH GetFont();
	void SetFont(LPDISPATCH newValue);
	LPDISPATCH GetDuplicate();
	long GetStoryType();
	LPDISPATCH GetTables();
	LPDISPATCH GetWords();
	LPDISPATCH GetSentences();
	LPDISPATCH GetCharacters();
	LPDISPATCH GetFootnotes();
	LPDISPATCH GetEndnotes();
	LPDISPATCH GetComments();
	LPDISPATCH GetCells();
	LPDISPATCH GetSections();
	LPDISPATCH GetParagraphs();
	LPDISPATCH GetBorders();
	void SetBorders(LPDISPATCH newValue);
	LPDISPATCH GetShading();
	LPDISPATCH GetTextRetrievalMode();
	void SetTextRetrievalMode(LPDISPATCH newValue);
	LPDISPATCH GetFields();
	LPDISPATCH GetFormFields();
	LPDISPATCH GetFrames();
	LPDISPATCH GetParagraphFormat();
	void SetParagraphFormat(LPDISPATCH newValue);
	LPDISPATCH GetListFormat();
	LPDISPATCH GetBookmarks();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	long GetBold();
	void SetBold(long nNewValue);
	long GetItalic();
	void SetItalic(long nNewValue);
	long GetUnderline();
	void SetUnderline(long nNewValue);
	long GetEmphasisMark();
	void SetEmphasisMark(long nNewValue);
	BOOL GetDisableCharacterSpaceGrid();
	void SetDisableCharacterSpaceGrid(BOOL bNewValue);
	LPDISPATCH GetRevisions();
	VARIANT GetStyle();
	void SetStyle(VARIANT* newValue);
	long GetStoryLength();
	long GetLanguageID();
	void SetLanguageID(long nNewValue);
	LPDISPATCH GetSynonymInfo();
	LPDISPATCH GetHyperlinks();
	LPDISPATCH GetListParagraphs();
	LPDISPATCH GetSubdocuments();
	BOOL GetGrammarChecked();
	void SetGrammarChecked(BOOL bNewValue);
	BOOL GetSpellingChecked();
	void SetSpellingChecked(BOOL bNewValue);
	long GetHighlightColorIndex();
	void SetHighlightColorIndex(long nNewValue);
	LPDISPATCH GetColumns();
	LPDISPATCH GetRows();
	BOOL GetIsEndOfRowMark();
	long GetBookmarkID();
	long GetPreviousBookmarkID();
	LPDISPATCH GetFind();
	LPDISPATCH GetPageSetup();
	void SetPageSetup(LPDISPATCH newValue);
	LPDISPATCH GetShapeRange();
	long GetCase();
	void SetCase(long nNewValue);
	VARIANT GetInformation(long Type);
	LPDISPATCH GetReadabilityStatistics();
	LPDISPATCH GetGrammaticalErrors();
	LPDISPATCH GetSpellingErrors();
	long GetOrientation();
	void SetOrientation(long nNewValue);
	LPDISPATCH GetInlineShapes();
	LPDISPATCH GetNextStoryRange();
	long GetLanguageIDFarEast();
	void SetLanguageIDFarEast(long nNewValue);
	long GetLanguageIDOther();
	void SetLanguageIDOther(long nNewValue);
	void Select();
	void SetRange(long Start, long End);
	void Collapse(VARIANT* Direction);
	void InsertBefore(LPCTSTR Text);
	void InsertAfter(LPCTSTR Text);
	LPDISPATCH Next(VARIANT* Unit, VARIANT* Count);
	LPDISPATCH Previous(VARIANT* Unit, VARIANT* Count);
	long StartOf(VARIANT* Unit, VARIANT* Extend);
	long EndOf(VARIANT* Unit, VARIANT* Extend);
	long Move(VARIANT* Unit, VARIANT* Count);
	long MoveStart(VARIANT* Unit, VARIANT* Count);
	long MoveEnd(VARIANT* Unit, VARIANT* Count);
	long MoveWhile(VARIANT* Cset, VARIANT* Count);
	long MoveStartWhile(VARIANT* Cset, VARIANT* Count);
	long MoveEndWhile(VARIANT* Cset, VARIANT* Count);
	long MoveUntil(VARIANT* Cset, VARIANT* Count);
	long MoveStartUntil(VARIANT* Cset, VARIANT* Count);
	long MoveEndUntil(VARIANT* Cset, VARIANT* Count);
	void Cut();
	void Copy();
	void Paste();
	void InsertBreak(VARIANT* Type);
	void InsertFile(LPCTSTR FileName, VARIANT* Range, VARIANT* ConfirmConversions, VARIANT* Link, VARIANT* Attachment);
	BOOL InStory(LPDISPATCH Range);
	BOOL InRange(LPDISPATCH Range);
	long Delete(VARIANT* Unit, VARIANT* Count);
	void WholeStory();
	long Expand(VARIANT* Unit);
	void InsertParagraph();
	void InsertParagraphAfter();
	void InsertSymbol(long CharacterNumber, VARIANT* Font, VARIANT* Unicode, VARIANT* Bias);
	void InsertCrossReference(VARIANT* ReferenceType, long ReferenceKind, VARIANT* ReferenceItem, VARIANT* InsertAsHyperlink, VARIANT* IncludePosition);
	void InsertCaption(VARIANT* Label, VARIANT* Title, VARIANT* TitleAutoText, VARIANT* Position);
	void CopyAsPicture();
	void SortAscending();
	void SortDescending();
	BOOL IsEqual(LPDISPATCH Range);
	float Calculate();
	LPDISPATCH GoTo(VARIANT* What, VARIANT* Which, VARIANT* Count, VARIANT* Name);
	LPDISPATCH GoToNext(long What);
	LPDISPATCH GoToPrevious(long What);
	void PasteSpecial(VARIANT* IconIndex, VARIANT* Link, VARIANT* Placement, VARIANT* DisplayAsIcon, VARIANT* DataType, VARIANT* IconFileName, VARIANT* IconLabel);
	void LookupNameProperties();
	long ComputeStatistics(long Statistic);
	void Relocate(long Direction);
	void CheckSynonyms();
	void SubscribeTo(LPCTSTR Edition, VARIANT* Format);
	void CreatePublisher(VARIANT* Edition, VARIANT* ContainsPICT, VARIANT* ContainsRTF, VARIANT* ContainsText);
	void InsertAutoText();
	void InsertDatabase(VARIANT* Format, VARIANT* Style, VARIANT* LinkToSource, VARIANT* Connection, VARIANT* SQLStatement, VARIANT* SQLStatement1, VARIANT* PasswordDocument, VARIANT* PasswordTemplate, VARIANT* WritePasswordDocument, 
		VARIANT* WritePasswordTemplate, VARIANT* DataSource, VARIANT* From, VARIANT* To, VARIANT* IncludeFields);
	void AutoFormat();
	void CheckGrammar();
	void CheckSpelling(VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* AlwaysSuggest, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, 
		VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10);
	LPDISPATCH GetSpellingSuggestions(VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* SuggestionMode, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, 
		VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10);
	void InsertParagraphBefore();
	void NextSubdocument();
	void PreviousSubdocument();
	void ConvertHangulAndHanja(VARIANT* ConversionsMode, VARIANT* FastConversion, VARIANT* CheckHangulEnding, VARIANT* EnableRecentOrdering, VARIANT* CustomDictionary);
	void PasteAsNestedTable();
	void ModifyEnclosure(VARIANT* Style, VARIANT* Symbol, VARIANT* EnclosedText);
	void PhoneticGuide(LPCTSTR Text, long Alignment, long Raise, long FontSize, LPCTSTR FontName);
	void InsertDateTime(VARIANT* DateTimeFormat, VARIANT* InsertAsField, VARIANT* InsertAsFullWidth, VARIANT* DateLanguage, VARIANT* CalendarType);
	void Sort(VARIANT* ExcludeHeader, VARIANT* FieldNumber, VARIANT* SortFieldType, VARIANT* SortOrder, VARIANT* FieldNumber2, VARIANT* SortFieldType2, VARIANT* SortOrder2, VARIANT* FieldNumber3, VARIANT* SortFieldType3, VARIANT* SortOrder3, 
		VARIANT* SortColumn, VARIANT* Separator, VARIANT* CaseSensitive, VARIANT* BidiSort, VARIANT* IgnoreThe, VARIANT* IgnoreKashida, VARIANT* IgnoreDiacritics, VARIANT* IgnoreHe, VARIANT* LanguageID);
	void DetectLanguage();
	LPDISPATCH ConvertToTable(VARIANT* Separator, VARIANT* NumRows, VARIANT* NumColumns, VARIANT* InitialColumnWidth, VARIANT* Format, VARIANT* ApplyBorders, VARIANT* ApplyShading, VARIANT* ApplyFont, VARIANT* ApplyColor, 
		VARIANT* ApplyHeadingRows, VARIANT* ApplyLastRow, VARIANT* ApplyFirstColumn, VARIANT* ApplyLastColumn, VARIANT* AutoFit, VARIANT* AutoFitBehavior, VARIANT* DefaultTableBehavior);
	void TCSCConverter(long WdTCSCConverterDirection, BOOL CommonTerms, BOOL UseVariants);
	BOOL GetLanguageDetected();
	void SetLanguageDetected(BOOL bNewValue);
	float GetFitTextWidth();
	void SetFitTextWidth(float newValue);
	long GetHorizontalInVertical();
	void SetHorizontalInVertical(long nNewValue);
	long GetTwoLinesInOne();
	void SetTwoLinesInOne(long nNewValue);
	BOOL GetCombineCharacters();
	void SetCombineCharacters(BOOL bNewValue);
	long GetNoProofing();
	void SetNoProofing(long nNewValue);
	LPDISPATCH GetTopLevelTables();
	LPDISPATCH GetScripts();
	long GetCharacterWidth();
	void SetCharacterWidth(long nNewValue);
	long GetKana();
	void SetKana(long nNewValue);
	long GetBoldBi();
	void SetBoldBi(long nNewValue);
	long GetItalicBi();
	void SetItalicBi(long nNewValue);
	CString GetId();
	void SetId(LPCTSTR lpszNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// Tables wrapper class

class Tables : public COleDispatchDriver
{
public:
	Tables() {}		// Calls COleDispatchDriver default constructor
	Tables(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Tables(const Tables& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	long GetCount();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Item(long Index);
	LPDISPATCH Add(LPDISPATCH Range, long NumRows, long NumColumns, VARIANT* DefaultTableBehavior, VARIANT* AutoFitBehavior);
	long GetNestingLevel();
};
/////////////////////////////////////////////////////////////////////////////
// Selection wrapper class

class Selection : public COleDispatchDriver
{
public:
	Selection() {}		// Calls COleDispatchDriver default constructor
	Selection(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Selection(const Selection& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetText();
	void SetText(LPCTSTR lpszNewValue);
	LPDISPATCH GetFormattedText();
	void SetFormattedText(LPDISPATCH newValue);
	long GetStart();
	void SetStart(long nNewValue);
	long GetEnd();
	void SetEnd(long nNewValue);
	LPDISPATCH GetFont();
	void SetFont(LPDISPATCH newValue);
	long GetType();
	long GetStoryType();
	VARIANT GetStyle();
	void SetStyle(VARIANT* newValue);
	LPDISPATCH GetTables();
	LPDISPATCH GetWords();
	LPDISPATCH GetSentences();
	LPDISPATCH GetCharacters();
	LPDISPATCH GetFootnotes();
	LPDISPATCH GetEndnotes();
	LPDISPATCH GetComments();
	LPDISPATCH GetCells();
	LPDISPATCH GetSections();
	LPDISPATCH GetParagraphs();
	LPDISPATCH GetBorders();
	void SetBorders(LPDISPATCH newValue);
	LPDISPATCH GetShading();
	LPDISPATCH GetFields();
	LPDISPATCH GetFormFields();
	LPDISPATCH GetFrames();
	LPDISPATCH GetParagraphFormat();
	void SetParagraphFormat(LPDISPATCH newValue);
	LPDISPATCH GetPageSetup();
	void SetPageSetup(LPDISPATCH newValue);
	LPDISPATCH GetBookmarks();
	long GetStoryLength();
	long GetLanguageID();
	void SetLanguageID(long nNewValue);
	long GetLanguageIDFarEast();
	void SetLanguageIDFarEast(long nNewValue);
	long GetLanguageIDOther();
	void SetLanguageIDOther(long nNewValue);
	LPDISPATCH GetHyperlinks();
	LPDISPATCH GetColumns();
	LPDISPATCH GetRows();
	LPDISPATCH GetHeaderFooter();
	BOOL GetIsEndOfRowMark();
	long GetBookmarkID();
	long GetPreviousBookmarkID();
	LPDISPATCH GetFind();
	LPDISPATCH GetRange();
	VARIANT GetInformation(long Type);
	long GetFlags();
	void SetFlags(long nNewValue);
	BOOL GetActive();
	BOOL GetStartIsActive();
	void SetStartIsActive(BOOL bNewValue);
	BOOL GetIPAtEndOfLine();
	BOOL GetExtendMode();
	void SetExtendMode(BOOL bNewValue);
	BOOL GetColumnSelectMode();
	void SetColumnSelectMode(BOOL bNewValue);
	long GetOrientation();
	void SetOrientation(long nNewValue);
	LPDISPATCH GetInlineShapes();
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetDocument();
	LPDISPATCH GetShapeRange();
	void Select();
	void SetRange(long Start, long End);
	void Collapse(VARIANT* Direction);
	void InsertBefore(LPCTSTR Text);
	void InsertAfter(LPCTSTR Text);
	LPDISPATCH Next(VARIANT* Unit, VARIANT* Count);
	LPDISPATCH Previous(VARIANT* Unit, VARIANT* Count);
	long StartOf(VARIANT* Unit, VARIANT* Extend);
	long EndOf(VARIANT* Unit, VARIANT* Extend);
	long Move(VARIANT* Unit, VARIANT* Count);
	long MoveStart(VARIANT* Unit, VARIANT* Count);
	long MoveEnd(VARIANT* Unit, VARIANT* Count);
	long MoveWhile(VARIANT* Cset, VARIANT* Count);
	long MoveStartWhile(VARIANT* Cset, VARIANT* Count);
	long MoveEndWhile(VARIANT* Cset, VARIANT* Count);
	long MoveUntil(VARIANT* Cset, VARIANT* Count);
	long MoveStartUntil(VARIANT* Cset, VARIANT* Count);
	long MoveEndUntil(VARIANT* Cset, VARIANT* Count);
	void Cut();
	void Copy();
	void Paste();
	void InsertBreak(VARIANT* Type);
	void InsertFile(LPCTSTR FileName, VARIANT* Range, VARIANT* ConfirmConversions, VARIANT* Link, VARIANT* Attachment);
	BOOL InStory(LPDISPATCH Range);
	BOOL InRange(LPDISPATCH Range);
	long Delete(VARIANT* Unit, VARIANT* Count);
	long Expand(VARIANT* Unit);
	void InsertParagraph();
	void InsertParagraphAfter();
	void InsertSymbol(long CharacterNumber, VARIANT* Font, VARIANT* Unicode, VARIANT* Bias);
	void InsertCrossReference(VARIANT* ReferenceType, long ReferenceKind, VARIANT* ReferenceItem, VARIANT* InsertAsHyperlink, VARIANT* IncludePosition);
	void InsertCaption(VARIANT* Label, VARIANT* Title, VARIANT* TitleAutoText, VARIANT* Position);
	void CopyAsPicture();
	void SortAscending();
	void SortDescending();
	BOOL IsEqual(LPDISPATCH Range);
	float Calculate();
	LPDISPATCH GoTo(VARIANT* What, VARIANT* Which, VARIANT* Count, VARIANT* Name);
	LPDISPATCH GoToNext(long What);
	LPDISPATCH GoToPrevious(long What);
	void PasteSpecial(VARIANT* IconIndex, VARIANT* Link, VARIANT* Placement, VARIANT* DisplayAsIcon, VARIANT* DataType, VARIANT* IconFileName, VARIANT* IconLabel);
	LPDISPATCH PreviousField();
	LPDISPATCH NextField();
	void InsertParagraphBefore();
	void InsertCells(VARIANT* ShiftCells);
	void Extend(VARIANT* Character);
	void Shrink();
	long MoveLeft(VARIANT* Unit, VARIANT* Count, VARIANT* Extend);
	long MoveRight(VARIANT* Unit, VARIANT* Count, VARIANT* Extend);
	long MoveUp(VARIANT* Unit, VARIANT* Count, VARIANT* Extend);
	long MoveDown(VARIANT* Unit, VARIANT* Count, VARIANT* Extend);
	long HomeKey(VARIANT* Unit, VARIANT* Extend);
	long EndKey(VARIANT* Unit, VARIANT* Extend);
	void EscapeKey();
	void TypeText(LPCTSTR Text);
	void CopyFormat();
	void PasteFormat();
	void TypeParagraph();
	void TypeBackspace();
	void NextSubdocument();
	void PreviousSubdocument();
	void SelectColumn();
	void SelectCurrentFont();
	void SelectCurrentAlignment();
	void SelectCurrentSpacing();
	void SelectCurrentIndent();
	void SelectCurrentTabs();
	void SelectCurrentColor();
	void CreateTextbox();
	void WholeStory();
	void SelectRow();
	void SplitTable();
	void InsertRows(VARIANT* NumRows);
	void InsertColumns();
	void InsertFormula(VARIANT* Formula, VARIANT* NumberFormat);
	LPDISPATCH NextRevision(VARIANT* Wrap);
	LPDISPATCH PreviousRevision(VARIANT* Wrap);
	void PasteAsNestedTable();
	LPDISPATCH CreateAutoTextEntry(LPCTSTR Name, LPCTSTR StyleName);
	void DetectLanguage();
	void SelectCell();
	void InsertRowsBelow(VARIANT* NumRows);
	void InsertColumnsRight();
	void InsertRowsAbove(VARIANT* NumRows);
	void RtlRun();
	void LtrRun();
	void BoldRun();
	void ItalicRun();
	void RtlPara();
	void LtrPara();
	void InsertDateTime(VARIANT* DateTimeFormat, VARIANT* InsertAsField, VARIANT* InsertAsFullWidth, VARIANT* DateLanguage, VARIANT* CalendarType);
	void Sort(VARIANT* ExcludeHeader, VARIANT* FieldNumber, VARIANT* SortFieldType, VARIANT* SortOrder, VARIANT* FieldNumber2, VARIANT* SortFieldType2, VARIANT* SortOrder2, VARIANT* FieldNumber3, VARIANT* SortFieldType3, VARIANT* SortOrder3, 
		VARIANT* SortColumn, VARIANT* Separator, VARIANT* CaseSensitive, VARIANT* BidiSort, VARIANT* IgnoreThe, VARIANT* IgnoreKashida, VARIANT* IgnoreDiacritics, VARIANT* IgnoreHe, VARIANT* LanguageID);
	LPDISPATCH ConvertToTable(VARIANT* Separator, VARIANT* NumRows, VARIANT* NumColumns, VARIANT* InitialColumnWidth, VARIANT* Format, VARIANT* ApplyBorders, VARIANT* ApplyShading, VARIANT* ApplyFont, VARIANT* ApplyColor, 
		VARIANT* ApplyHeadingRows, VARIANT* ApplyLastRow, VARIANT* ApplyFirstColumn, VARIANT* ApplyLastColumn, VARIANT* AutoFit, VARIANT* AutoFitBehavior, VARIANT* DefaultTableBehavior);
	long GetNoProofing();
	void SetNoProofing(long nNewValue);
	LPDISPATCH GetTopLevelTables();
	BOOL GetLanguageDetected();
	void SetLanguageDetected(BOOL bNewValue);
	float GetFitTextWidth();
	void SetFitTextWidth(float newValue);
};
