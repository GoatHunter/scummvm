/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef SCUMM_SMUSH_FONT_H
#define SCUMM_SMUSH_FONT_H

#include "common/scummsys.h"
#include "scumm/nut_renderer.h"

namespace Scumm {

class SmushFont : public NutRenderer {
protected:
	int16 _color;
	bool _new_colors;
	bool _original;


	int getStringWidth(const char *str, uint numBytesMax);
	int getStringHeight(const char *str, uint numBytesMax);
	int draw2byte(byte *buffer, int dst_width, int x, int y, int idx);
	int drawChar(byte *buffer, int dst_width, int x, int y, byte chr);
	void drawSubstring(const char *str, uint numBytesMax, byte *buffer, int dst_width, int x, int y);

public:
	SmushFont(ScummEngine *vm, const char *filename, bool use_original_colors, bool new_colors);

	void setColor(byte c) { _color = c; }
	void drawString    (const char *str, byte *buffer, Common::Rect &clipRect, int x, int y, bool center);
	void drawStringWrap(const char *str, byte *buffer, Common::Rect &clipRect, int x, int y, bool center);

	static inline bool is2ByteCharacter(Common::Language lang, byte c) {
		if (lang == Common::JA_JPN)
			return (c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFD);
		else if (lang == Common::KO_KOR)
			return (c >= 0xB0 && c <= 0xD0);
		else if (lang == Common::ZH_TWN || lang == Common::ZH_CHN)
			return (c >= 0x80);
		return false;
	}
};

} // End of namespace Scumm

#endif
