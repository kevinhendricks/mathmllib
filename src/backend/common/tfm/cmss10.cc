// Copyright (C) 2000-2007, Luca Padovani <padovani@sti.uniurb.it>.
// 
// This file is part of GtkMathView, a flexible, high-quality rendering
// engine for MathML documents.
// 
// GtkMathView is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as published
// by the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
// 
// GtkMathView is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "TFM.hh"

static TFM::Font font = {
"CMSS",

  0xea,
  "TeX text",
  0x00a00000,
  0x6d23bd52,
  7,
  128
};

static TFM::Dimension dimension[] = {
  { 0x01, "slant", 0x00000000 },
  { 0x02, "space", 0x00055556 },
  { 0x03, "space_stretch", 0x0002aaab },
  { 0x04, "space_shrink", 0x0001c71d },
  { 0x05, "x_height", 0x00071c72 },
  { 0x06, "quad", 0x00100003 },
  { 0x07, "extra_space", 0x0001c71d }
};


static TFM::Kerning C_0b_Kerning[] = {
  { 0x21, 0x00011c72 },
  { 0x27, 0x00011c72 },
  { 0x29, 0x00011c72 },
  { 0x3f, 0x00011c72 },
  { 0x5d, 0x00011c72 }
};

static TFM::Kerning C_20_Kerning[] = {
  { 0x4c, 0xfffbdddb },
  { 0x6c, 0xfffc2d82 }
};

static TFM::Kerning C_27_Kerning[] = {
  { 0x21, 0x0001c71d },
  { 0x3f, 0x0001c71d }
};

static TFM::Kerning C_41_Kerning[] = {
  { 0x43, 0xffff8e38 },
  { 0x47, 0xffff8e38 },
  { 0x4f, 0xffff8e38 },
  { 0x51, 0xffff8e38 },
  { 0x54, 0xfffeaaaa },
  { 0x55, 0xffff8e38 },
  { 0x56, 0xfffe38e3 },
  { 0x57, 0xfffe38e3 },
  { 0x59, 0xfffeaaaa },
  { 0x74, 0xffff8e38 }
};

static TFM::Kerning C_44_Kerning[] = {
  { 0x41, 0xffff8e38 },
  { 0x56, 0xffff8e38 },
  { 0x57, 0xffff8e38 },
  { 0x58, 0xffff8e38 },
  { 0x59, 0xffff8e38 }
};

static TFM::Kerning C_46_Kerning[] = {
  { 0x41, 0xfffeaaaa },
  { 0x43, 0xffff8e38 },
  { 0x47, 0xffff8e38 },
  { 0x4f, 0xffff8e38 },
  { 0x51, 0xffff8e38 },
  { 0x61, 0xffff8e38 },
  { 0x65, 0xffff8e38 },
  { 0x6f, 0xffff8e38 },
  { 0x72, 0xffff8e38 },
  { 0x75, 0xffff8e38 }
};

static TFM::Kerning C_49_Kerning[] = {
  { 0x49, 0x000071c8 }
};

static TFM::Kerning C_4b_Kerning[] = {
  { 0x43, 0xffff8e38 },
  { 0x47, 0xffff8e38 },
  { 0x4f, 0xffff8e38 },
  { 0x51, 0xffff8e38 }
};

static TFM::Kerning C_4c_Kerning[] = {
  { 0x54, 0xfffeaaaa },
  { 0x56, 0xfffe38e3 },
  { 0x57, 0xfffe38e3 },
  { 0x59, 0xfffeaaaa }
};

static TFM::Kerning C_4f_Kerning[] = {
  { 0x41, 0xffff8e38 },
  { 0x56, 0xffff8e38 },
  { 0x57, 0xffff8e38 },
  { 0x58, 0xffff8e38 },
  { 0x59, 0xffff8e38 }
};

static TFM::Kerning C_50_Kerning[] = {
  { 0x2c, 0xfffeaaaa },
  { 0x2e, 0xfffeaaaa },
  { 0x41, 0xfffeaaaa },
  { 0x61, 0xffff8e38 },
  { 0x65, 0xffff8e38 },
  { 0x6f, 0xffff8e38 }
};

static TFM::Kerning C_54_Kerning[] = {
  { 0x41, 0xfffeaaaa },
  { 0x61, 0xfffeaaaa },
  { 0x65, 0xfffeaaaa },
  { 0x6f, 0xfffeaaaa },
  { 0x72, 0xfffeaaaa },
  { 0x75, 0xfffeaaaa },
  { 0x79, 0xfffeaaaa }
};

static TFM::Kerning C_56_Kerning[] = {
  { 0x41, 0xfffeaaaa },
  { 0x43, 0xffff8e38 },
  { 0x47, 0xffff8e38 },
  { 0x4f, 0xffff8e38 },
  { 0x51, 0xffff8e38 },
  { 0x61, 0xffff8e38 },
  { 0x65, 0xffff8e38 },
  { 0x6f, 0xffff8e38 },
  { 0x72, 0xffff8e38 },
  { 0x75, 0xffff8e38 }
};

static TFM::Kerning C_57_Kerning[] = {
  { 0x41, 0xfffeaaaa },
  { 0x43, 0xffff8e38 },
  { 0x47, 0xffff8e38 },
  { 0x4f, 0xffff8e38 },
  { 0x51, 0xffff8e38 },
  { 0x61, 0xffff8e38 },
  { 0x65, 0xffff8e38 },
  { 0x6f, 0xffff8e38 },
  { 0x72, 0xffff8e38 },
  { 0x75, 0xffff8e38 }
};

static TFM::Kerning C_58_Kerning[] = {
  { 0x43, 0xffff8e38 },
  { 0x47, 0xffff8e38 },
  { 0x4f, 0xffff8e38 },
  { 0x51, 0xffff8e38 }
};

static TFM::Kerning C_59_Kerning[] = {
  { 0x41, 0xfffeaaaa },
  { 0x61, 0xfffeaaaa },
  { 0x65, 0xfffeaaaa },
  { 0x6f, 0xfffeaaaa },
  { 0x72, 0xfffeaaaa },
  { 0x75, 0xfffeaaaa }
};

static TFM::Kerning C_61_Kerning[] = {
  { 0x72, 0xffff8e38 },
  { 0x77, 0xffff8e38 },
  { 0x79, 0xffff8e38 }
};

static TFM::Kerning C_62_Kerning[] = {
  { 0x63, 0x000071c8 },
  { 0x64, 0x000071c8 },
  { 0x65, 0x000071c8 },
  { 0x6f, 0x000071c8 },
  { 0x71, 0x000071c8 },
  { 0x72, 0xffff8e38 },
  { 0x77, 0xffff8e38 },
  { 0x78, 0xffff8e38 },
  { 0x79, 0xffff8e38 }
};

static TFM::Kerning C_66_Kerning[] = {
  { 0x21, 0x00011c72 },
  { 0x27, 0x00011c72 },
  { 0x29, 0x00011c72 },
  { 0x3f, 0x00011c72 },
  { 0x5d, 0x00011c72 }
};

static TFM::Kerning C_67_Kerning[] = {
  { 0x6a, 0x000071c8 }
};

static TFM::Kerning C_6b_Kerning[] = {
  { 0x61, 0xffff8e38 },
  { 0x63, 0xffff8e38 },
  { 0x65, 0xffff8e38 },
  { 0x6f, 0xffff8e38 }
};

static TFM::Kerning C_6f_Kerning[] = {
  { 0x63, 0x000071c8 },
  { 0x64, 0x000071c8 },
  { 0x65, 0x000071c8 },
  { 0x6f, 0x000071c8 },
  { 0x71, 0x000071c8 },
  { 0x72, 0xffff8e38 },
  { 0x77, 0xffff8e38 },
  { 0x78, 0xffff8e38 },
  { 0x79, 0xffff8e38 }
};

static TFM::Kerning C_70_Kerning[] = {
  { 0x63, 0x000071c8 },
  { 0x64, 0x000071c8 },
  { 0x65, 0x000071c8 },
  { 0x6f, 0x000071c8 },
  { 0x71, 0x000071c8 },
  { 0x72, 0xffff8e38 },
  { 0x77, 0xffff8e38 },
  { 0x78, 0xffff8e38 },
  { 0x79, 0xffff8e38 }
};

static TFM::Kerning C_74_Kerning[] = {
  { 0x77, 0xffff8e38 },
  { 0x79, 0xffff8e38 }
};

static TFM::Kerning C_75_Kerning[] = {
  { 0x77, 0xffff8e38 }
};

static TFM::Kerning C_77_Kerning[] = {
  { 0x61, 0xffff8e38 },
  { 0x63, 0xffff8e38 },
  { 0x65, 0xffff8e38 },
  { 0x6f, 0xffff8e38 }
};

static TFM::Kerning C_79_Kerning[] = {
  { 0x2c, 0xfffeaaaa },
  { 0x2e, 0xfffeaaaa },
  { 0x61, 0xffff8e38 },
  { 0x65, 0xffff8e38 },
  { 0x6f, 0xffff8e38 }
};

static TFM::Ligature C_0b_Ligature[] = {
  { 0x69, 0x00, 0x0e },
  { 0x6c, 0x00, 0x0f }
};

static TFM::Ligature C_21_Ligature[] = {
  { 0x60, 0x00, 0x3c }
};

static TFM::Ligature C_27_Ligature[] = {
  { 0x27, 0x00, 0x22 }
};

static TFM::Ligature C_2d_Ligature[] = {
  { 0x2d, 0x00, 0x7b }
};

static TFM::Ligature C_3f_Ligature[] = {
  { 0x60, 0x00, 0x3e }
};

static TFM::Ligature C_60_Ligature[] = {
  { 0x60, 0x00, 0x5c }
};

static TFM::Ligature C_66_Ligature[] = {
  { 0x66, 0x00, 0x0b },
  { 0x69, 0x00, 0x0c },
  { 0x6c, 0x00, 0x0d }
};

static TFM::Ligature C_7b_Ligature[] = {
  { 0x2d, 0x00, 0x7c }
};


static TFM::Character character[] = {
  { 0x00, 0x0008aaad, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x01, 0x000d5558, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x02, 0x000c71ca, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x03, 0x0009c720, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x04, 0x000aaaad, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x05, 0x000b555a, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x06, 0x000b8e3b, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x07, 0x000c71ca, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x08, 0x000b8e3b, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x09, 0x000c71ca, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0a, 0x000b8e3b, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0b, 0x00095558, 0x000b1c72, 0x00000000, 0x00011c72, 5, C_0b_Kerning, 2, C_0b_Ligature },
  { 0x0c, 0x000893eb, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0d, 0x000893eb, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0e, 0x000d05b3, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0f, 0x000d05b3, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x10, 0x0003d27e, 0x00071c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x11, 0x00044446, 0x00071c72, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x12, 0x00080002, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x13, 0x00080002, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x14, 0x00080002, 0x000a1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x15, 0x00080002, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x16, 0x00080002, 0x0009be00, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x17, 0x000aaaae, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x18, 0x00071c73, 0x00000000, 0x0002b8e3, 0x00000000, 0, 0, 0, 0 },
  { 0x19, 0x0007b05e, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1a, 0x000b8e3b, 0x00071c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1b, 0x000c71ca, 0x00071c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1c, 0x00080002, 0x0008aaab, 0x00018e3a, 0x00000000, 0, 0, 0, 0 },
  { 0x1d, 0x000dc720, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1e, 0x000f8e3d, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1f, 0x000c71ca, 0x000be38e, 0x0000c71d, 0x00000000, 0, 0, 0, 0 },
  { 0x20, 0x0003d27e, 0x00071c72, 0x00000000, 0x00000000, 2, C_20_Kerning, 0, 0 },
  { 0x21, 0x00051c73, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 1, C_21_Ligature },
  { 0x22, 0x00080002, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x23, 0x000d5558, 0x000b1c72, 0x00031c70, 0x00000000, 0, 0, 0, 0 },
  { 0x24, 0x00080002, 0x000c0000, 0x0000e38e, 0x00000000, 0, 0, 0, 0 },
  { 0x25, 0x000d5558, 0x000c0000, 0x0000e38e, 0x00000000, 0, 0, 0, 0 },
  { 0x26, 0x000c2225, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x27, 0x000471c8, 0x000b1c72, 0x00000000, 0x00000000, 2, C_27_Kerning, 1, C_27_Ligature },
  { 0x28, 0x000638e5, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x29, 0x000638e5, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x2a, 0x00080002, 0x000c0000, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x2b, 0x000c71ca, 0x00095556, 0x00015556, 0x00000000, 0, 0, 0, 0 },
  { 0x2c, 0x000471c8, 0x00015555, 0x00020000, 0x00000000, 0, 0, 0, 0 },
  { 0x2d, 0x00055556, 0x00071c72, 0x00000000, 0x00000000, 0, 0, 1, C_2d_Ligature },
  { 0x2e, 0x000471c8, 0x00015555, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x2f, 0x00080002, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x30, 0x00080002, 0x000a7d28, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x31, 0x00080002, 0x000a7d28, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x32, 0x00080002, 0x000a7d28, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x33, 0x00080002, 0x000a7d28, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x34, 0x00080002, 0x000a7d28, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x35, 0x00080002, 0x000a7d28, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x36, 0x00080002, 0x000a7d28, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x37, 0x00080002, 0x000a7d28, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x38, 0x00080002, 0x000a7d28, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x39, 0x00080002, 0x000a7d28, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x3a, 0x000471c8, 0x00071c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x3b, 0x000471c8, 0x00071c72, 0x00020000, 0x00000000, 0, 0, 0, 0 },
  { 0x3c, 0x00051c73, 0x00080000, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x3d, 0x000c71ca, 0x0005eb85, 0xfffdeb85, 0x00000000, 0, 0, 0, 0 },
  { 0x3e, 0x00078e3b, 0x00080000, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x3f, 0x00078e3b, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 1, C_3f_Ligature },
  { 0x40, 0x000aaaad, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x41, 0x000aaaae, 0x000b1c72, 0x00000000, 0x00000000, 10, C_41_Kerning, 0, 0 },
  { 0x42, 0x000aaaae, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x43, 0x000a38e6, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x44, 0x000b8e3d, 0x000b1c72, 0x00000000, 0x00000000, 5, C_44_Kerning, 0, 0 },
  { 0x45, 0x00098e3b, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x46, 0x00091c75, 0x000b1c72, 0x00000000, 0x00000000, 10, C_46_Kerning, 0, 0 },
  { 0x47, 0x000aaaad, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x48, 0x000b555a, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x49, 0x000471ca, 0x000b1c72, 0x00000000, 0x00000000, 1, C_49_Kerning, 0, 0 },
  { 0x4a, 0x00078e3b, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4b, 0x000b1c76, 0x000b1c72, 0x00000000, 0x00000000, 4, C_4b_Kerning, 0, 0 },
  { 0x4c, 0x0008aaad, 0x000b1c72, 0x00000000, 0x00000000, 4, C_4c_Kerning, 0, 0 },
  { 0x4d, 0x000e0005, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4e, 0x000b555a, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4f, 0x000bc71e, 0x000b1c72, 0x00000000, 0x00000000, 5, C_4f_Kerning, 0, 0 },
  { 0x50, 0x000a38e6, 0x000b1c72, 0x00000000, 0x00000000, 6, C_50_Kerning, 0, 0 },
  { 0x51, 0x000bc71e, 0x000b1c72, 0x00020000, 0x00000000, 0, 0, 0, 0 },
  { 0x52, 0x000a5558, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x53, 0x0008e390, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x54, 0x000ae390, 0x000b1c72, 0x00000000, 0x00000000, 7, C_54_Kerning, 0, 0 },
  { 0x55, 0x000b0005, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x56, 0x000aaaae, 0x000b1c72, 0x00000000, 0x000038e3, 10, C_56_Kerning, 0, 0 },
  { 0x57, 0x000f1c76, 0x000b1c72, 0x00000000, 0x000038e3, 10, C_57_Kerning, 0, 0 },
  { 0x58, 0x000aaaae, 0x000b1c72, 0x00000000, 0x00000000, 4, C_58_Kerning, 0, 0 },
  { 0x59, 0x000aaaae, 0x000b1c72, 0x00000000, 0x00006666, 6, C_59_Kerning, 0, 0 },
  { 0x5a, 0x0009c71e, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5b, 0x00049f4b, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x5c, 0x00080002, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5d, 0x00049f4b, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x5e, 0x00080002, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5f, 0x000471c8, 0x000adeae, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x60, 0x000471c8, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 1, C_60_Ligature },
  { 0x61, 0x0007b05d, 0x00071c72, 0x00000000, 0x00000000, 3, C_61_Kerning, 0, 0 },
  { 0x62, 0x00084446, 0x000b1c72, 0x00000000, 0x00000000, 9, C_62_Kerning, 0, 0 },
  { 0x63, 0x00071c73, 0x00071c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x64, 0x00084446, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x65, 0x00071c73, 0x00071c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x66, 0x0004e390, 0x000b1c72, 0x00000000, 0x00011c72, 5, C_66_Kerning, 3, C_66_Ligature },
  { 0x67, 0x00080002, 0x00071c72, 0x00031c72, 0x000038e3, 1, C_67_Kerning, 0, 0 },
  { 0x68, 0x00084446, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x69, 0x0003d27e, 0x000adeae, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x6a, 0x00044446, 0x000adeae, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x6b, 0x0007d280, 0x000b1c72, 0x00000000, 0x00000000, 4, C_6b_Kerning, 0, 0 },
  { 0x6c, 0x0003d27e, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x6d, 0x000cb60e, 0x00071c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x6e, 0x00084446, 0x00071c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x6f, 0x00080002, 0x00071c72, 0x00000000, 0x00000000, 9, C_6f_Kerning, 0, 0 },
  { 0x70, 0x00084446, 0x00071c72, 0x00031c72, 0x00000000, 9, C_70_Kerning, 0, 0 },
  { 0x71, 0x00084446, 0x00071c72, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x72, 0x0005777a, 0x00071c72, 0x00000000, 0x000038e3, 0, 0, 0, 0 },
  { 0x73, 0x00062223, 0x00071c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x74, 0x0005c71d, 0x00092495, 0x00000000, 0x00000000, 2, C_74_Kerning, 0, 0 },
  { 0x75, 0x00084446, 0x00071c72, 0x00000000, 0x00000000, 1, C_75_Kerning, 0, 0 },
  { 0x76, 0x000760b8, 0x00071c72, 0x00000000, 0x000038e3, 0, 0, 0, 0 },
  { 0x77, 0x000aeef2, 0x00071c72, 0x00000000, 0x000038e3, 4, C_77_Kerning, 0, 0 },
  { 0x78, 0x000760b8, 0x00071c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x79, 0x000760b8, 0x00071c72, 0x00031c72, 0x000038e3, 5, C_79_Kerning, 0, 0 },
  { 0x7a, 0x0006f4a0, 0x00071c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7b, 0x00080002, 0x00071c72, 0x00000000, 0x000071c8, 0, 0, 1, C_7b_Ligature },
  { 0x7c, 0x00100003, 0x00071c72, 0x00000000, 0x000071c8, 0, 0, 0, 0 },
  { 0x7d, 0x00080002, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7e, 0x00080002, 0x000ad34e, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7f, 0x00080002, 0x000adeae, 0x00000000, 0x00000000, 0, 0, 0, 0 }
};

void
cmss10_tables(TFM::Font*& _font, TFM::Dimension*& _dimension, TFM::Character*& _character)
{
  _font = &font;
  _dimension = dimension;
  _character = character;
}
