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
"CMBX",

  0xf2,
  "TeX text",
  0x00600000,
  0x8045c074,
  7,
  128
};

static TFM::Dimension dimension[] = {
  { 0x01, "slant", 0x00000000 },
  { 0x02, "space", 0x00077f0b },
  { 0x03, "space_stretch", 0x00039998 },
  { 0x04, "space_shrink", 0x00026665 },
  { 0x05, "x_height", 0x00071c73 },
  { 0x06, "quad", 0x00163145 },
  { 0x07, "extra_space", 0x00026665 }
};


static TFM::Kerning C_0b_Kerning[] = {
  { 0x21, 0x0001ff0d },
  { 0x27, 0x0001ff0d },
  { 0x29, 0x0001ff0d },
  { 0x3f, 0x0001ff0d },
  { 0x5d, 0x0001ff0d }
};

static TFM::Kerning C_20_Kerning[] = {
  { 0x4c, 0xfff8cccb },
  { 0x6c, 0xfff9b428 }
};

static TFM::Kerning C_27_Kerning[] = {
  { 0x21, 0x00026665 },
  { 0x3f, 0x00026665 }
};

static TFM::Kerning C_41_Kerning[] = {
  { 0x43, 0xffff6665 },
  { 0x47, 0xffff6665 },
  { 0x4f, 0xffff6665 },
  { 0x51, 0xffff6665 },
  { 0x54, 0xfffe3333 },
  { 0x55, 0xffff6665 },
  { 0x56, 0xfffd999b },
  { 0x57, 0xfffd999b },
  { 0x59, 0xfffe3333 },
  { 0x74, 0xffff6665 }
};

static TFM::Kerning C_44_Kerning[] = {
  { 0x41, 0xffff6665 },
  { 0x56, 0xffff6665 },
  { 0x57, 0xffff6665 },
  { 0x58, 0xffff6665 },
  { 0x59, 0xffff6665 }
};

static TFM::Kerning C_46_Kerning[] = {
  { 0x41, 0xfffd999b },
  { 0x43, 0xffff6665 },
  { 0x47, 0xffff6665 },
  { 0x4f, 0xffff6665 },
  { 0x51, 0xffff6665 },
  { 0x61, 0xfffe3333 },
  { 0x65, 0xfffe3333 },
  { 0x6f, 0xfffe3333 },
  { 0x72, 0xfffe3333 },
  { 0x75, 0xfffe3333 }
};

static TFM::Kerning C_49_Kerning[] = {
  { 0x49, 0x0000999b }
};

static TFM::Kerning C_4b_Kerning[] = {
  { 0x43, 0xffff6665 },
  { 0x47, 0xffff6665 },
  { 0x4f, 0xffff6665 },
  { 0x51, 0xffff6665 }
};

static TFM::Kerning C_4c_Kerning[] = {
  { 0x54, 0xfffe3333 },
  { 0x56, 0xfffd999b },
  { 0x57, 0xfffd999b },
  { 0x59, 0xfffe3333 }
};

static TFM::Kerning C_4f_Kerning[] = {
  { 0x41, 0xffff6665 },
  { 0x56, 0xffff6665 },
  { 0x57, 0xffff6665 },
  { 0x58, 0xffff6665 },
  { 0x59, 0xffff6665 }
};

static TFM::Kerning C_50_Kerning[] = {
  { 0x2c, 0xfffe3333 },
  { 0x2e, 0xfffe3333 },
  { 0x41, 0xfffe3333 },
  { 0x61, 0xffff6665 },
  { 0x65, 0xffff6665 },
  { 0x6f, 0xffff6665 }
};

static TFM::Kerning C_52_Kerning[] = {
  { 0x43, 0xffff6665 },
  { 0x47, 0xffff6665 },
  { 0x4f, 0xffff6665 },
  { 0x51, 0xffff6665 },
  { 0x54, 0xfffe3333 },
  { 0x55, 0xffff6665 },
  { 0x56, 0xfffd999b },
  { 0x57, 0xfffd999b },
  { 0x59, 0xfffe3333 },
  { 0x74, 0xffff6665 }
};

static TFM::Kerning C_54_Kerning[] = {
  { 0x41, 0xfffe3333 },
  { 0x61, 0xfffe3333 },
  { 0x65, 0xfffe3333 },
  { 0x6f, 0xfffe3333 },
  { 0x72, 0xfffe3333 },
  { 0x75, 0xfffe3333 },
  { 0x79, 0xffff6665 }
};

static TFM::Kerning C_56_Kerning[] = {
  { 0x41, 0xfffd999b },
  { 0x43, 0xffff6665 },
  { 0x47, 0xffff6665 },
  { 0x4f, 0xffff6665 },
  { 0x51, 0xffff6665 },
  { 0x61, 0xfffe3333 },
  { 0x65, 0xfffe3333 },
  { 0x6f, 0xfffe3333 },
  { 0x72, 0xfffe3333 },
  { 0x75, 0xfffe3333 }
};

static TFM::Kerning C_57_Kerning[] = {
  { 0x41, 0xfffd999b },
  { 0x43, 0xffff6665 },
  { 0x47, 0xffff6665 },
  { 0x4f, 0xffff6665 },
  { 0x51, 0xffff6665 },
  { 0x61, 0xfffe3333 },
  { 0x65, 0xfffe3333 },
  { 0x6f, 0xfffe3333 },
  { 0x72, 0xfffe3333 },
  { 0x75, 0xfffe3333 }
};

static TFM::Kerning C_58_Kerning[] = {
  { 0x43, 0xffff6665 },
  { 0x47, 0xffff6665 },
  { 0x4f, 0xffff6665 },
  { 0x51, 0xffff6665 }
};

static TFM::Kerning C_59_Kerning[] = {
  { 0x41, 0xfffe3333 },
  { 0x61, 0xfffe3333 },
  { 0x65, 0xfffe3333 },
  { 0x6f, 0xfffe3333 },
  { 0x72, 0xfffe3333 },
  { 0x75, 0xfffe3333 }
};

static TFM::Kerning C_61_Kerning[] = {
  { 0x6a, 0x00013333 },
  { 0x76, 0xffff6665 },
  { 0x77, 0xffff6665 },
  { 0x79, 0xffff6665 }
};

static TFM::Kerning C_62_Kerning[] = {
  { 0x63, 0x0000999b },
  { 0x64, 0x0000999b },
  { 0x65, 0x0000999b },
  { 0x6a, 0x00013333 },
  { 0x6f, 0x0000999b },
  { 0x71, 0x0000999b },
  { 0x76, 0xffff6665 },
  { 0x77, 0xffff6665 },
  { 0x78, 0xffff6665 },
  { 0x79, 0xffff6665 }
};

static TFM::Kerning C_63_Kerning[] = {
  { 0x68, 0xffff6665 },
  { 0x6b, 0xffff6665 }
};

static TFM::Kerning C_66_Kerning[] = {
  { 0x21, 0x0001ff0d },
  { 0x27, 0x0001ff0d },
  { 0x29, 0x0001ff0d },
  { 0x3f, 0x0001ff0d },
  { 0x5d, 0x0001ff0d }
};

static TFM::Kerning C_67_Kerning[] = {
  { 0x6a, 0x0000999b }
};

static TFM::Kerning C_68_Kerning[] = {
  { 0x62, 0xffff6665 },
  { 0x74, 0xffff6665 },
  { 0x75, 0xffff6665 },
  { 0x76, 0xffff6665 },
  { 0x77, 0xffff6665 },
  { 0x79, 0xffff6665 }
};

static TFM::Kerning C_6b_Kerning[] = {
  { 0x61, 0xfffecccd },
  { 0x61, 0xffff6665 },
  { 0x63, 0xffff6665 },
  { 0x65, 0xffff6665 },
  { 0x6f, 0xffff6665 }
};

static TFM::Kerning C_6d_Kerning[] = {
  { 0x62, 0xffff6665 },
  { 0x74, 0xffff6665 },
  { 0x75, 0xffff6665 },
  { 0x76, 0xffff6665 },
  { 0x77, 0xffff6665 },
  { 0x79, 0xffff6665 }
};

static TFM::Kerning C_6e_Kerning[] = {
  { 0x62, 0xffff6665 },
  { 0x74, 0xffff6665 },
  { 0x75, 0xffff6665 },
  { 0x76, 0xffff6665 },
  { 0x77, 0xffff6665 },
  { 0x79, 0xffff6665 }
};

static TFM::Kerning C_6f_Kerning[] = {
  { 0x63, 0x0000999b },
  { 0x64, 0x0000999b },
  { 0x65, 0x0000999b },
  { 0x6a, 0x00013333 },
  { 0x6f, 0x0000999b },
  { 0x71, 0x0000999b },
  { 0x76, 0xffff6665 },
  { 0x77, 0xffff6665 },
  { 0x78, 0xffff6665 },
  { 0x79, 0xffff6665 }
};

static TFM::Kerning C_70_Kerning[] = {
  { 0x63, 0x0000999b },
  { 0x64, 0x0000999b },
  { 0x65, 0x0000999b },
  { 0x6a, 0x00013333 },
  { 0x6f, 0x0000999b },
  { 0x71, 0x0000999b },
  { 0x76, 0xffff6665 },
  { 0x77, 0xffff6665 },
  { 0x78, 0xffff6665 },
  { 0x79, 0xffff6665 }
};

static TFM::Kerning C_74_Kerning[] = {
  { 0x77, 0xffff6665 },
  { 0x79, 0xffff6665 }
};

static TFM::Kerning C_75_Kerning[] = {
  { 0x77, 0xffff6665 }
};

static TFM::Kerning C_76_Kerning[] = {
  { 0x61, 0xfffecccd },
  { 0x61, 0xffff6665 },
  { 0x63, 0xffff6665 },
  { 0x65, 0xffff6665 },
  { 0x6f, 0xffff6665 }
};

static TFM::Kerning C_77_Kerning[] = {
  { 0x61, 0xffff6665 },
  { 0x63, 0xffff6665 },
  { 0x65, 0xffff6665 },
  { 0x6f, 0xffff6665 }
};

static TFM::Kerning C_79_Kerning[] = {
  { 0x2c, 0xfffe3333 },
  { 0x2e, 0xfffe3333 },
  { 0x61, 0xffff6665 },
  { 0x65, 0xffff6665 },
  { 0x6f, 0xffff6665 }
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
  { 0x00, 0x000d3330, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x01, 0x00124bd3, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x02, 0x001118a0, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x03, 0x000f425b, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x04, 0x000eb23b, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x05, 0x00110975, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x06, 0x000fe56d, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x07, 0x001118a0, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x08, 0x000fe56d, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x09, 0x001118a0, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0a, 0x000fe56d, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0b, 0x000d314b, 0x000b1c73, 0x00000000, 0x0001ff0d, 5, C_0b_Kerning, 2, C_0b_Ligature },
  { 0x0c, 0x000c97b0, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0d, 0x000c97b0, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0e, 0x0012e388, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0f, 0x0012e388, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x10, 0x00064bd8, 0x00071c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x11, 0x0006e573, 0x00071c73, 0x00031c73, 0x00000000, 0, 0, 0, 0 },
  { 0x12, 0x000b18a3, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x13, 0x000b18a3, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x14, 0x000b18a3, 0x000a1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x15, 0x000b18a3, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x16, 0x000b18a3, 0x0009c71b, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x17, 0x0010758d, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x18, 0x0009e570, 0x00000000, 0x0002b8e5, 0x00000000, 0, 0, 0, 0 },
  { 0x19, 0x000b5370, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1a, 0x000fe56d, 0x00071c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1b, 0x001118a0, 0x00071c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1c, 0x000b18a3, 0x0008aaad, 0x00018e3b, 0x00000000, 0, 0, 0, 0 },
  { 0x1d, 0x0013c715, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1e, 0x00162d7b, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1f, 0x001118a0, 0x000bc16d, 0x0000c71d, 0x00000000, 0, 0, 0, 0 },
  { 0x20, 0x00064bd8, 0x00071c73, 0x00000000, 0x00000000, 2, C_20_Kerning, 0, 0 },
  { 0x21, 0x0006dfc0, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 1, C_21_Ligature },
  { 0x22, 0x000b5ce8, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x23, 0x00124bd3, 0x000b1c73, 0x00031c70, 0x00000000, 0, 0, 0, 0 },
  { 0x24, 0x000b18a3, 0x000c0000, 0x0000e38d, 0x00000000, 0, 0, 0, 0 },
  { 0x25, 0x00124bd3, 0x000c0000, 0x0000e38d, 0x00000000, 0, 0, 0, 0 },
  { 0x26, 0x001118a0, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x27, 0x00064bd8, 0x000b1c73, 0x00000000, 0x00000000, 2, C_27_Kerning, 1, C_27_Ligature },
  { 0x28, 0x0008b23d, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x29, 0x0008b23d, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x2a, 0x000b18a3, 0x000c0000, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x2b, 0x001118a0, 0x000b3330, 0x00033330, 0x00000000, 0, 0, 0, 0 },
  { 0x2c, 0x00064bd8, 0x0002aaab, 0x00031c73, 0x00000000, 0, 0, 0, 0 },
  { 0x2d, 0x00077f0b, 0x00071c73, 0x00000000, 0x00000000, 0, 0, 1, C_2d_Ligature },
  { 0x2e, 0x00064bd8, 0x0002aaab, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x2f, 0x000b18a3, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x30, 0x000b18a3, 0x000a4fa5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x31, 0x000b18a3, 0x000a4fa5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x32, 0x000b18a3, 0x000a4fa5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x33, 0x000b18a3, 0x000a4fa5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x34, 0x000b18a3, 0x000a4fa5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x35, 0x000b18a3, 0x000a4fa5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x36, 0x000b18a3, 0x000a4fa5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x37, 0x000b18a3, 0x000a4fa5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x38, 0x000b18a3, 0x000a4fa5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x39, 0x000b18a3, 0x000a4fa5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x3a, 0x00064bd8, 0x00071c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x3b, 0x00064bd8, 0x00071c73, 0x00031c73, 0x00000000, 0, 0, 0, 0 },
  { 0x3c, 0x0006dfc0, 0x00080000, 0x00031c73, 0x00000000, 0, 0, 0, 0 },
  { 0x3d, 0x001118a0, 0x0006b05d, 0xfffeb05d, 0x00000000, 0, 0, 0, 0 },
  { 0x3e, 0x000a7f0b, 0x00080000, 0x00031c73, 0x00000000, 0, 0, 0, 0 },
  { 0x3f, 0x000a7f0b, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 1, C_3f_Ligature },
  { 0x40, 0x001118a0, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x41, 0x0010758d, 0x000afa50, 0x00000000, 0x00000000, 10, C_41_Kerning, 0, 0 },
  { 0x42, 0x000f93e5, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x43, 0x000fe56d, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x44, 0x0010c718, 0x000afa50, 0x00000000, 0x00000000, 5, C_44_Kerning, 0, 0 },
  { 0x45, 0x000e6663, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x46, 0x000dcccb, 0x000afa50, 0x00000000, 0x00000000, 10, C_46_Kerning, 0, 0 },
  { 0x47, 0x00113ca8, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x48, 0x00110975, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x49, 0x00081a8d, 0x000afa50, 0x00000000, 0x00000000, 1, C_49_Kerning, 0, 0 },
  { 0x4a, 0x000b60b3, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4b, 0x00110f28, 0x000afa50, 0x00000000, 0x00000000, 4, C_4b_Kerning, 0, 0 },
  { 0x4c, 0x000d3330, 0x000afa50, 0x00000000, 0x00000000, 4, C_4c_Kerning, 0, 0 },
  { 0x4d, 0x0014a30d, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4e, 0x00110975, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4f, 0x001084b8, 0x000afa50, 0x00000000, 0x00000000, 5, C_4f_Kerning, 0, 0 },
  { 0x50, 0x000efa4b, 0x000afa50, 0x00000000, 0x00000000, 6, C_50_Kerning, 0, 0 },
  { 0x51, 0x001084b8, 0x000afa50, 0x00031c73, 0x00000000, 0, 0, 0, 0 },
  { 0x52, 0x00104fa0, 0x000afa50, 0x00000000, 0x00000000, 10, C_52_Kerning, 0, 0 },
  { 0x53, 0x000c4bd5, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x54, 0x000f5185, 0x000afa50, 0x00000000, 0x00000000, 7, C_54_Kerning, 0, 0 },
  { 0x55, 0x0010bf83, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x56, 0x0010758d, 0x000afa50, 0x00000000, 0x00004ccd, 10, C_56_Kerning, 0, 0 },
  { 0x57, 0x0016758b, 0x000afa50, 0x00000000, 0x00004ccd, 10, C_57_Kerning, 0, 0 },
  { 0x58, 0x0010758d, 0x000afa50, 0x00000000, 0x00000000, 4, C_58_Kerning, 0, 0 },
  { 0x59, 0x0010758d, 0x000afa50, 0x00000000, 0x00008a3d, 6, C_59_Kerning, 0, 0 },
  { 0x5a, 0x000d7f08, 0x000afa50, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5b, 0x000652ad, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x5c, 0x000b5ce8, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5d, 0x000652ad, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x5e, 0x000b18a3, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5f, 0x00064bd8, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x60, 0x00064bd8, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 1, C_60_Ligature },
  { 0x61, 0x000acbd5, 0x00071c73, 0x00000000, 0x00000000, 4, C_61_Kerning, 0, 0 },
  { 0x62, 0x000c4bd5, 0x000b1c73, 0x00000000, 0x00000000, 10, C_62_Kerning, 0, 0 },
  { 0x63, 0x0009e570, 0x00071c73, 0x00000000, 0x00000000, 2, C_63_Kerning, 0, 0 },
  { 0x64, 0x000c4bd5, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x65, 0x000a24f8, 0x00071c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x66, 0x0006e573, 0x000b1c73, 0x00000000, 0x0001ff0d, 5, C_66_Kerning, 3, C_66_Ligature },
  { 0x67, 0x000b18a3, 0x00071c73, 0x00031c73, 0x00004ccd, 1, C_67_Kerning, 0, 0 },
  { 0x68, 0x000c4bd5, 0x000b1c73, 0x00000000, 0x00000000, 6, C_68_Kerning, 0, 0 },
  { 0x69, 0x00064bd8, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x6a, 0x0006e573, 0x000b1c73, 0x00031c73, 0x00000000, 0, 0, 0, 0 },
  { 0x6b, 0x000bb23d, 0x000b1c73, 0x00000000, 0x00000000, 5, C_6b_Kerning, 0, 0 },
  { 0x6c, 0x00064bd8, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x6d, 0x00124bd3, 0x00071c73, 0x00000000, 0x00000000, 6, C_6d_Kerning, 0, 0 },
  { 0x6e, 0x000c4bd5, 0x00071c73, 0x00000000, 0x00000000, 6, C_6e_Kerning, 0, 0 },
  { 0x6f, 0x000b18a3, 0x00071c73, 0x00000000, 0x00000000, 10, C_6f_Kerning, 0, 0 },
  { 0x70, 0x000c4bd5, 0x00071c73, 0x00031c73, 0x00000000, 10, C_70_Kerning, 0, 0 },
  { 0x71, 0x000bb23b, 0x00071c73, 0x00031c73, 0x00000000, 0, 0, 0, 0 },
  { 0x72, 0x00092315, 0x00071c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x73, 0x0008d0f5, 0x00071c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x74, 0x0008b23d, 0x000a28a5, 0x00000000, 0x00000000, 2, C_74_Kerning, 0, 0 },
  { 0x75, 0x000c4bd5, 0x00071c73, 0x00000000, 0x00000000, 1, C_75_Kerning, 0, 0 },
  { 0x76, 0x000bb23d, 0x00071c73, 0x00000000, 0x00004ccd, 5, C_76_Kerning, 0, 0 },
  { 0x77, 0x000fe56d, 0x00071c73, 0x00000000, 0x00004ccd, 4, C_77_Kerning, 0, 0 },
  { 0x78, 0x000bb23d, 0x00071c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x79, 0x000bb23d, 0x00071c73, 0x00031c73, 0x00004ccd, 5, C_79_Kerning, 0, 0 },
  { 0x7a, 0x0009e570, 0x00071c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7b, 0x000b18a3, 0x00071c73, 0x00000000, 0x0000999b, 0, 0, 1, C_7b_Ligature },
  { 0x7c, 0x00163145, 0x00071c73, 0x00000000, 0x0000999b, 0, 0, 0, 0 },
  { 0x7d, 0x000b18a3, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7e, 0x000b18a3, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7f, 0x000b18a3, 0x000b1c73, 0x00000000, 0x00000000, 0, 0, 0, 0 }
};

void
cmbx6_tables(TFM::Font*& _font, TFM::Dimension*& _dimension, TFM::Character*& _character)
{
  _font = &font;
  _dimension = dimension;
  _character = character;
}
