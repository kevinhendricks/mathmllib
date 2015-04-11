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
"CMR",

  0xee,
  "TeX text",
  0x00800000,
  0x7c7b5907,
  7,
  128
};

static TFM::Dimension dimension[] = {
  { 0x01, "slant", 0x00000000 },
  { 0x02, "space", 0x0005aab0 },
  { 0x03, "space_stretch", 0x0002d558 },
  { 0x04, "space_shrink", 0x0001e390 },
  { 0x05, "x_height", 0x0006e38e },
  { 0x06, "quad", 0x00110010 },
  { 0x07, "extra_space", 0x0001e390 }
};


static TFM::Kerning C_0b_Kerning[] = {
  { 0x21, 0x0001438e },
  { 0x27, 0x0001438e },
  { 0x29, 0x0001438e },
  { 0x3f, 0x0001438e },
  { 0x5d, 0x0001438e }
};

static TFM::Kerning C_20_Kerning[] = {
  { 0x4c, 0xfffa93e4 },
  { 0x6c, 0xfffb4718 }
};

static TFM::Kerning C_27_Kerning[] = {
  { 0x21, 0x0001e390 },
  { 0x3f, 0x0001e390 }
};

static TFM::Kerning C_41_Kerning[] = {
  { 0x43, 0xffff871c },
  { 0x47, 0xffff871c },
  { 0x4f, 0xffff871c },
  { 0x51, 0xffff871c },
  { 0x54, 0xfffe9554 },
  { 0x55, 0xffff871c },
  { 0x56, 0xfffe1c70 },
  { 0x57, 0xfffe1c70 },
  { 0x59, 0xfffe9554 },
  { 0x74, 0xffff871c }
};

static TFM::Kerning C_44_Kerning[] = {
  { 0x41, 0xffff871c },
  { 0x56, 0xffff871c },
  { 0x57, 0xffff871c },
  { 0x58, 0xffff871c },
  { 0x59, 0xffff871c }
};

static TFM::Kerning C_46_Kerning[] = {
  { 0x41, 0xfffe1c70 },
  { 0x43, 0xffff871c },
  { 0x47, 0xffff871c },
  { 0x4f, 0xffff871c },
  { 0x51, 0xffff871c },
  { 0x61, 0xfffe9554 },
  { 0x65, 0xfffe9554 },
  { 0x6f, 0xfffe9554 },
  { 0x72, 0xfffe9554 },
  { 0x75, 0xfffe9554 }
};

static TFM::Kerning C_49_Kerning[] = {
  { 0x49, 0x000078e4 }
};

static TFM::Kerning C_4b_Kerning[] = {
  { 0x43, 0xffff871c },
  { 0x47, 0xffff871c },
  { 0x4f, 0xffff871c },
  { 0x51, 0xffff871c }
};

static TFM::Kerning C_4c_Kerning[] = {
  { 0x54, 0xfffe9554 },
  { 0x56, 0xfffe1c70 },
  { 0x57, 0xfffe1c70 },
  { 0x59, 0xfffe9554 }
};

static TFM::Kerning C_4f_Kerning[] = {
  { 0x41, 0xffff871c },
  { 0x56, 0xffff871c },
  { 0x57, 0xffff871c },
  { 0x58, 0xffff871c },
  { 0x59, 0xffff871c }
};

static TFM::Kerning C_50_Kerning[] = {
  { 0x2c, 0xfffe9554 },
  { 0x2e, 0xfffe9554 },
  { 0x41, 0xfffe9554 },
  { 0x61, 0xffff871c },
  { 0x65, 0xffff871c },
  { 0x6f, 0xffff871c }
};

static TFM::Kerning C_52_Kerning[] = {
  { 0x43, 0xffff871c },
  { 0x47, 0xffff871c },
  { 0x4f, 0xffff871c },
  { 0x51, 0xffff871c },
  { 0x54, 0xfffe9554 },
  { 0x55, 0xffff871c },
  { 0x56, 0xfffe1c70 },
  { 0x57, 0xfffe1c70 },
  { 0x59, 0xfffe9554 },
  { 0x74, 0xffff871c }
};

static TFM::Kerning C_54_Kerning[] = {
  { 0x41, 0xfffe9554 },
  { 0x61, 0xfffe9554 },
  { 0x65, 0xfffe9554 },
  { 0x6f, 0xfffe9554 },
  { 0x72, 0xfffe9554 },
  { 0x75, 0xfffe9554 },
  { 0x79, 0xffff871c }
};

static TFM::Kerning C_56_Kerning[] = {
  { 0x41, 0xfffe1c70 },
  { 0x43, 0xffff871c },
  { 0x47, 0xffff871c },
  { 0x4f, 0xffff871c },
  { 0x51, 0xffff871c },
  { 0x61, 0xfffe9554 },
  { 0x65, 0xfffe9554 },
  { 0x6f, 0xfffe9554 },
  { 0x72, 0xfffe9554 },
  { 0x75, 0xfffe9554 }
};

static TFM::Kerning C_57_Kerning[] = {
  { 0x41, 0xfffe1c70 },
  { 0x43, 0xffff871c },
  { 0x47, 0xffff871c },
  { 0x4f, 0xffff871c },
  { 0x51, 0xffff871c },
  { 0x61, 0xfffe9554 },
  { 0x65, 0xfffe9554 },
  { 0x6f, 0xfffe9554 },
  { 0x72, 0xfffe9554 },
  { 0x75, 0xfffe9554 }
};

static TFM::Kerning C_58_Kerning[] = {
  { 0x43, 0xffff871c },
  { 0x47, 0xffff871c },
  { 0x4f, 0xffff871c },
  { 0x51, 0xffff871c }
};

static TFM::Kerning C_59_Kerning[] = {
  { 0x41, 0xfffe9554 },
  { 0x61, 0xfffe9554 },
  { 0x65, 0xfffe9554 },
  { 0x6f, 0xfffe9554 },
  { 0x72, 0xfffe9554 },
  { 0x75, 0xfffe9554 }
};

static TFM::Kerning C_61_Kerning[] = {
  { 0x6a, 0x0000f1c8 },
  { 0x76, 0xffff871c },
  { 0x77, 0xffff871c },
  { 0x79, 0xffff871c }
};

static TFM::Kerning C_62_Kerning[] = {
  { 0x63, 0x000078e4 },
  { 0x64, 0x000078e4 },
  { 0x65, 0x000078e4 },
  { 0x6a, 0x0000f1c8 },
  { 0x6f, 0x000078e4 },
  { 0x71, 0x000078e4 },
  { 0x76, 0xffff871c },
  { 0x77, 0xffff871c },
  { 0x78, 0xffff871c },
  { 0x79, 0xffff871c }
};

static TFM::Kerning C_63_Kerning[] = {
  { 0x68, 0xffff871c },
  { 0x6b, 0xffff871c }
};

static TFM::Kerning C_66_Kerning[] = {
  { 0x21, 0x0001438e },
  { 0x27, 0x0001438e },
  { 0x29, 0x0001438e },
  { 0x3f, 0x0001438e },
  { 0x5d, 0x0001438e }
};

static TFM::Kerning C_67_Kerning[] = {
  { 0x6a, 0x000078e4 }
};

static TFM::Kerning C_68_Kerning[] = {
  { 0x62, 0xffff871c },
  { 0x74, 0xffff871c },
  { 0x75, 0xffff871c },
  { 0x76, 0xffff871c },
  { 0x77, 0xffff871c },
  { 0x79, 0xffff871c }
};

static TFM::Kerning C_6b_Kerning[] = {
  { 0x61, 0xffff0e38 },
  { 0x61, 0xffff871c },
  { 0x63, 0xffff871c },
  { 0x65, 0xffff871c },
  { 0x6f, 0xffff871c }
};

static TFM::Kerning C_6d_Kerning[] = {
  { 0x62, 0xffff871c },
  { 0x74, 0xffff871c },
  { 0x75, 0xffff871c },
  { 0x76, 0xffff871c },
  { 0x77, 0xffff871c },
  { 0x79, 0xffff871c }
};

static TFM::Kerning C_6e_Kerning[] = {
  { 0x62, 0xffff871c },
  { 0x74, 0xffff871c },
  { 0x75, 0xffff871c },
  { 0x76, 0xffff871c },
  { 0x77, 0xffff871c },
  { 0x79, 0xffff871c }
};

static TFM::Kerning C_6f_Kerning[] = {
  { 0x63, 0x000078e4 },
  { 0x64, 0x000078e4 },
  { 0x65, 0x000078e4 },
  { 0x6a, 0x0000f1c8 },
  { 0x6f, 0x000078e4 },
  { 0x71, 0x000078e4 },
  { 0x76, 0xffff871c },
  { 0x77, 0xffff871c },
  { 0x78, 0xffff871c },
  { 0x79, 0xffff871c }
};

static TFM::Kerning C_70_Kerning[] = {
  { 0x63, 0x000078e4 },
  { 0x64, 0x000078e4 },
  { 0x65, 0x000078e4 },
  { 0x6a, 0x0000f1c8 },
  { 0x6f, 0x000078e4 },
  { 0x71, 0x000078e4 },
  { 0x76, 0xffff871c },
  { 0x77, 0xffff871c },
  { 0x78, 0xffff871c },
  { 0x79, 0xffff871c }
};

static TFM::Kerning C_74_Kerning[] = {
  { 0x77, 0xffff871c },
  { 0x79, 0xffff871c }
};

static TFM::Kerning C_75_Kerning[] = {
  { 0x77, 0xffff871c }
};

static TFM::Kerning C_76_Kerning[] = {
  { 0x61, 0xffff0e38 },
  { 0x61, 0xffff871c },
  { 0x63, 0xffff871c },
  { 0x65, 0xffff871c },
  { 0x6f, 0xffff871c }
};

static TFM::Kerning C_77_Kerning[] = {
  { 0x61, 0xffff871c },
  { 0x63, 0xffff871c },
  { 0x65, 0xffff871c },
  { 0x6f, 0xffff871c }
};

static TFM::Kerning C_79_Kerning[] = {
  { 0x2c, 0xfffe9554 },
  { 0x2e, 0xfffe9554 },
  { 0x61, 0xffff871c },
  { 0x65, 0xffff871c },
  { 0x6f, 0xffff871c }
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
  { 0x00, 0x000a9de8, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x01, 0x000e2ab8, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x02, 0x000d38f0, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x03, 0x000bca00, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x04, 0x000b5560, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x05, 0x000cbbc8, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x06, 0x000c4728, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x07, 0x000d38f0, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x08, 0x000c4728, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x09, 0x000d38f0, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0a, 0x000c4728, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0b, 0x0009eab4, 0x000b1c72, 0x00000000, 0x0001438e, 5, C_0b_Kerning, 2, C_0b_Ligature },
  { 0x0c, 0x000971d0, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0d, 0x000971d0, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0e, 0x000e2ab8, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x0f, 0x000e2ab8, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x10, 0x0004b8e8, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x11, 0x000531cc, 0x0006e38e, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x12, 0x00088008, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x13, 0x00088008, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x14, 0x00088008, 0x000a0e3a, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x15, 0x00088008, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x16, 0x00088008, 0x00092d82, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x17, 0x000cbbc8, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x18, 0x00078e40, 0x00000000, 0x0002b8e4, 0x00000000, 0, 0, 0, 0 },
  { 0x19, 0x00088008, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1a, 0x000c4728, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1b, 0x000d38f0, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1c, 0x00088008, 0x000871c8, 0x00018e3a, 0x00000000, 0, 0, 0, 0 },
  { 0x1d, 0x000f56d0, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1e, 0x00113a60, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x1f, 0x000d38f0, 0x000bb60a, 0x0000c71c, 0x00000000, 0, 0, 0, 0 },
  { 0x20, 0x0004b8e8, 0x0006e38e, 0x00000000, 0x00000000, 2, C_20_Kerning, 0, 0 },
  { 0x21, 0x0004b8e8, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 1, C_21_Ligature },
  { 0x22, 0x00088008, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x23, 0x000e2ab8, 0x000b1c72, 0x00031c70, 0x00000000, 0, 0, 0, 0 },
  { 0x24, 0x00088008, 0x000c0000, 0x0000e38e, 0x00000000, 0, 0, 0, 0 },
  { 0x25, 0x000e2ab8, 0x000c0000, 0x0000e38e, 0x00000000, 0, 0, 0, 0 },
  { 0x26, 0x000d38f0, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x27, 0x0004b8e8, 0x000b1c72, 0x00000000, 0x00000000, 2, C_27_Kerning, 1, C_27_Ligature },
  { 0x28, 0x00069c78, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x29, 0x00069c78, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x2a, 0x00088008, 0x000c0000, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x2b, 0x000d38f0, 0x0009aab0, 0x0001aab0, 0x00000000, 0, 0, 0, 0 },
  { 0x2c, 0x0004b8e8, 0x0001c71c, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x2d, 0x0005aab0, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 1, C_2d_Ligature },
  { 0x2e, 0x0004b8e8, 0x0001c71c, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x2f, 0x00088008, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x30, 0x00088008, 0x000a4fa6, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x31, 0x00088008, 0x000a4fa6, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x32, 0x00088008, 0x000a4fa6, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x33, 0x00088008, 0x000a4fa6, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x34, 0x00088008, 0x000a4fa6, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x35, 0x00088008, 0x000a4fa6, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x36, 0x00088008, 0x000a4fa6, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x37, 0x00088008, 0x000a4fa6, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x38, 0x00088008, 0x000a4fa6, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x39, 0x00088008, 0x000a4fa6, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x3a, 0x0004b8e8, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x3b, 0x0004b8e8, 0x0006e38e, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x3c, 0x0004b8e8, 0x00080000, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x3d, 0x000d38f0, 0x00060c3c, 0xfffe0c3c, 0x00000000, 0, 0, 0, 0 },
  { 0x3e, 0x00080724, 0x00080000, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x3f, 0x00080724, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 1, C_3f_Ligature },
  { 0x40, 0x000d38f0, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x41, 0x000cbbc8, 0x000aeeee, 0x00000000, 0x00000000, 10, C_41_Kerning, 0, 0 },
  { 0x42, 0x000c0894, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x43, 0x000c4728, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x44, 0x000cfa5c, 0x000aeeee, 0x00000000, 0x00000000, 5, C_44_Kerning, 0, 0 },
  { 0x45, 0x000b8fb0, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x46, 0x000b16cc, 0x000aeeee, 0x00000000, 0x00000000, 10, C_46_Kerning, 0, 0 },
  { 0x47, 0x000d5618, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x48, 0x000cbbc8, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x49, 0x00061f50, 0x000aeeee, 0x00000000, 0x00000000, 1, C_49_Kerning, 0, 0 },
  { 0x4a, 0x0008ba58, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4b, 0x000d34ac, 0x000aeeee, 0x00000000, 0x00000000, 4, C_4b_Kerning, 0, 0 },
  { 0x4c, 0x000a9de8, 0x000aeeee, 0x00000000, 0x00000000, 4, C_4c_Kerning, 0, 0 },
  { 0x4d, 0x000f9120, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4e, 0x000cbbc8, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4f, 0x000d38f0, 0x000aeeee, 0x00000000, 0x00000000, 5, C_4f_Kerning, 0, 0 },
  { 0x50, 0x000b8fb0, 0x000aeeee, 0x00000000, 0x00000000, 6, C_50_Kerning, 0, 0 },
  { 0x51, 0x000d38f0, 0x000aeeee, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x52, 0x000c8178, 0x000aeeee, 0x00000000, 0x00000000, 10, C_52_Kerning, 0, 0 },
  { 0x53, 0x000971d0, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x54, 0x000c4728, 0x000aeeee, 0x00000000, 0x00000000, 7, C_54_Kerning, 0, 0 },
  { 0x55, 0x000cbbc8, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x56, 0x000cbbc8, 0x000aeeee, 0x00000000, 0x00003c72, 10, C_56_Kerning, 0, 0 },
  { 0x57, 0x001174b0, 0x000aeeee, 0x00000000, 0x00003c72, 10, C_57_Kerning, 0, 0 },
  { 0x58, 0x000cbbc8, 0x000aeeee, 0x00000000, 0x00000000, 4, C_58_Kerning, 0, 0 },
  { 0x59, 0x000cbbc8, 0x000aeeee, 0x00000000, 0x00006cce, 6, C_59_Kerning, 0, 0 },
  { 0x5a, 0x000a6398, 0x000aeeee, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5b, 0x0004b8e8, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x5c, 0x00088008, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5d, 0x0004b8e8, 0x000c0000, 0x00040000, 0x00000000, 0, 0, 0, 0 },
  { 0x5e, 0x00088008, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5f, 0x0004b8e8, 0x000abaec, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x60, 0x0004b8e8, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 1, C_60_Ligature },
  { 0x61, 0x00088008, 0x0006e38e, 0x00000000, 0x00000000, 4, C_61_Kerning, 0, 0 },
  { 0x62, 0x000971d0, 0x000b1c72, 0x00000000, 0x00000000, 10, C_62_Kerning, 0, 0 },
  { 0x63, 0x00078e40, 0x0006e38e, 0x00000000, 0x00000000, 2, C_63_Kerning, 0, 0 },
  { 0x64, 0x000971d0, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x65, 0x00078e40, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x66, 0x000531cc, 0x000b1c72, 0x00000000, 0x0001438e, 5, C_66_Kerning, 3, C_66_Ligature },
  { 0x67, 0x00088008, 0x0006e38e, 0x00031c72, 0x00003c72, 1, C_67_Kerning, 0, 0 },
  { 0x68, 0x000971d0, 0x000b1c72, 0x00000000, 0x00000000, 6, C_68_Kerning, 0, 0 },
  { 0x69, 0x0004b8e8, 0x000abaec, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x6a, 0x000531cc, 0x000abaec, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x6b, 0x0008f8ec, 0x000b1c72, 0x00000000, 0x00000000, 5, C_6b_Kerning, 0, 0 },
  { 0x6c, 0x0004b8e8, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x6d, 0x000e2ab8, 0x0006e38e, 0x00000000, 0x00000000, 6, C_6d_Kerning, 0, 0 },
  { 0x6e, 0x000971d0, 0x0006e38e, 0x00000000, 0x00000000, 6, C_6e_Kerning, 0, 0 },
  { 0x6f, 0x00088008, 0x0006e38e, 0x00000000, 0x00000000, 10, C_6f_Kerning, 0, 0 },
  { 0x70, 0x000971d0, 0x0006e38e, 0x00031c72, 0x00000000, 10, C_70_Kerning, 0, 0 },
  { 0x71, 0x0008f8ec, 0x0006e38e, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x72, 0x0006a006, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x73, 0x0006b4a6, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x74, 0x00069c78, 0x0009d75e, 0x00000000, 0x00000000, 2, C_74_Kerning, 0, 0 },
  { 0x75, 0x000971d0, 0x0006e38e, 0x00000000, 0x00000000, 1, C_75_Kerning, 0, 0 },
  { 0x76, 0x0008f8ec, 0x0006e38e, 0x00000000, 0x00003c72, 5, C_76_Kerning, 0, 0 },
  { 0x77, 0x000c4728, 0x0006e38e, 0x00000000, 0x00003c72, 4, C_77_Kerning, 0, 0 },
  { 0x78, 0x0008f8ec, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x79, 0x0008f8ec, 0x0006e38e, 0x00031c72, 0x00003c72, 5, C_79_Kerning, 0, 0 },
  { 0x7a, 0x00078e40, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7b, 0x00088008, 0x0006e38e, 0x00000000, 0x000078e4, 0, 0, 1, C_7b_Ligature },
  { 0x7c, 0x00110010, 0x0006e38e, 0x00000000, 0x000078e4, 0, 0, 0, 0 },
  { 0x7d, 0x00088008, 0x000b1c72, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7e, 0x00088008, 0x000abaec, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7f, 0x00088008, 0x000abaec, 0x00000000, 0x00000000, 0, 0, 0, 0 }
};

void
cmr8_tables(TFM::Font*& _font, TFM::Dimension*& _dimension, TFM::Character*& _character)
{
  _font = &font;
  _dimension = dimension;
  _character = character;
}
