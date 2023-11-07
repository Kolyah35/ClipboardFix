#include <Geode/Geode.hpp>
#include <Geode/modify/InfoLayer.hpp>

using namespace geode::prelude;

void clipboardWin(char const* output) {	
    size_t const len = strlen(output) + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();	
}

class $modify(InfoLayer){
	void copyToClipboard(int a2) {
		InfoLayer::copyToClipboard(a2);

		clipboardWin(fmt::format("{}", this->m_level->m_levelID.value()).c_str());
	}
};