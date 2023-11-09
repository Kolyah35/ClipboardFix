#include <Geode/Geode.hpp>
#include <Geode/modify/InfoLayer.hpp>
#include <Geode/utils/general.hpp>

using namespace geode::prelude;

class $modify(InfoLayer){
	void copyToClipboard(int a2) {
		InfoLayer::copyToClipboard(a2);

		clipboard::write(fmt::format("{}", this->m_level->m_levelID.value()));
	}
};
