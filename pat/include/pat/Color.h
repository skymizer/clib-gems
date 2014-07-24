//===- Color.h --------------------------------------------------------===//
//
//                     The pat Team
//
// This file is distributed under the New BSD License. 
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef PAT_SUPPORT_COLOR_H
#define PAT_SUPPORT_COLOR_H
#include <iosfwd>
#include <iomanip>

namespace pat {

/** \class Color
 *  \brief Color is a std::ostream manipulator for changing the color.
 */
class Color
{
public:
  // color order matches ANSI escape sequence, don't change
  enum kColor {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,

    RESET
  };

  enum kType {
    NORMAL,
    BOLD,
    BACKGROUND
  };

public:
  Color(kColor pColor = BLACK, kType pType = NORMAL);

  static Color Bold(kColor pColor);

  static Color BackGround(kColor pColor);

  void setColor(std::ostream& pOS);

private:
  kColor m_Color : 24;
  kType m_Type : 8;
};

} // namespace of pat

namespace std {

ostream& operator<<(ostream& pOS, pat::Color pColor);
ostream& operator<<(ostream& pOS, pat::Color::kColor pColor);

} // namespace of std

#endif
