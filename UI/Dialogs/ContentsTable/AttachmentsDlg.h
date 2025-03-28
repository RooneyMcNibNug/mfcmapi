#pragma once
#include <UI/Dialogs/ContentsTable/ContentsTableDlg.h>

namespace dialog
{
	class CAttachmentsDlg : public CContentsTableDlg
	{
	public:
		CAttachmentsDlg(
			_In_ std::shared_ptr<cache::CMapiObjects> lpMapiObjects,
			_In_ LPMAPITABLE lpMAPITable,
			_In_ LPMAPIPROP lpMessage);
		~CAttachmentsDlg();

	private:
		// Overrides from base class
		void HandleAddInMenuSingle(
			_In_ LPADDINMENUPARAMS lpParams,
			_In_ LPMAPIPROP lpMAPIProp,
			_In_ LPMAPICONTAINER lpContainer) override;
		void HandleCopy() override;
		_Check_return_ bool HandlePaste() override;
		void OnDeleteSelectedItem() override;
		void OnDisplayItem() override;
		void OnInitMenu(_In_ CMenu* pMenu) override;
		_Check_return_ LPATTACH OpenAttach(ULONG ulAttachNum, bool bCache);
		_Check_return_ LPMESSAGE OpenEmbeddedMessage(LPATTACH lpAttach) const;
		_Check_return_ LPMAPIPROP OpenItemProp(int iSelectedItem, modifyType bModify) override;

		// Menu items
		void OnModifySelectedItem();
		void OnSaveChanges();
		void OnSaveToFile();
		void OnViewEmbeddedMessageProps();
		void OnAddAttachment();

		LPATTACH m_lpAttach{}; // Currently opened attachment
		ULONG m_ulAttachNum{static_cast<ULONG>(-1)}; // Currently opened attachment number
		LPMESSAGE m_lpMessage{};
		bool m_bDisplayAttachAsEmbeddedMessage{};

		DECLARE_MESSAGE_MAP()
	};
} // namespace dialog