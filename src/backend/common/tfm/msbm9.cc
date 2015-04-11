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
"MSBM",

  0xec,
  "TeX math symbols",
  0x00900000,
  0xaa00b561,
  22,
  128
};

static TFM::Dimension dimension[] = {
  { 0x01, "slant", 0x00040000 },
  { 0x02, "space", 0x0004ccd0 },
  { 0x03, "space_stretch", 0x00026660 },
  { 0x04, "space_shrink", 0x000199a0 },
  { 0x05, "x_height", 0x0007684c },
  { 0x06, "quad", 0x00100000 },
  { 0x07, "extra_space", 0x000199a0 },
  { 0x08, "num1", 0x000a590b },
  { 0x09, "num2", 0x00068e24 },
  { 0x0a, "num3", 0x0007327c },
  { 0x0b, "denom1", 0x000ada00 },
  { 0x0c, "denom2", 0x00056deb },
  { 0x0d, "sup1", 0x0007af95 },
  { 0x0e, "sup2", 0x0006cc07 },
  { 0x0f, "sup3", 0x000497b4 },
  { 0x10, "sub1", 0x0001c71c },
  { 0x11, "sub2", 0x0002d09e },
  { 0x12, "supdrop", 0x0005a134 },
  { 0x13, "subdrop", 0x0000e38e },
  { 0x14, "delim1", 0x002a7d27 },
  { 0x15, "delim2", 0x00102d84 },
  { 0x16, "axis_height", 0x00040000 }
};



static TFM::Character character[] = {
  { 0x00, 0x000cca40, 0x000c7740, 0x00046420, 0x00000000, 0, 0, 0, 0 },
  { 0x01, 0x000cca40, 0x000c7740, 0x00046420, 0x00000000, 0, 0, 0, 0 },
  { 0x02, 0x000cca40, 0x000d3007, 0x00052e4b, 0x00000000, 0, 0, 0, 0 },
  { 0x03, 0x000cca40, 0x000d3007, 0x00052e4b, 0x00000000, 0, 0, 0, 0 },
  { 0x04, 0x000cca40, 0x000b8e69, 0x00038e69, 0x00000000, 0, 0, 0, 0 },
  { 0x05, 0x000cca40, 0x000b8e69, 0x00038e69, 0x00000000, 0, 0, 0, 0 },
  { 0x06, 0x000cca40, 0x000b8e69, 0x00038e69, 0x00000000, 0, 0, 0, 0 },
  { 0x07, 0x000cca40, 0x000b8e69, 0x00038e69, 0x00000000, 0, 0, 0, 0 },
  { 0x08, 0x000cca40, 0x000c7740, 0x00046420, 0x00000000, 0, 0, 0, 0 },
  { 0x09, 0x000cca40, 0x000c7740, 0x00046420, 0x00000000, 0, 0, 0, 0 },
  { 0x0a, 0x000cca40, 0x000d3007, 0x00052e4b, 0x00000000, 0, 0, 0, 0 },
  { 0x0b, 0x000cca40, 0x000d3007, 0x00052e4b, 0x00000000, 0, 0, 0, 0 },
  { 0x0c, 0x000cca40, 0x000a6f37, 0x00026f37, 0x00000000, 0, 0, 0, 0 },
  { 0x0d, 0x000cca40, 0x000a6f37, 0x00026f37, 0x00000000, 0, 0, 0, 0 },
  { 0x0e, 0x000cca40, 0x000d3007, 0x00052e4b, 0x00000000, 0, 0, 0, 0 },
  { 0x0f, 0x000cca40, 0x000d3007, 0x00052e4b, 0x00000000, 0, 0, 0, 0 },
  { 0x10, 0x000cca40, 0x000c005c, 0x0004005c, 0x00000000, 0, 0, 0, 0 },
  { 0x11, 0x000cca40, 0x000c005c, 0x0004005c, 0x00000000, 0, 0, 0, 0 },
  { 0x12, 0x000cca40, 0x000c005c, 0x0004005c, 0x00000000, 0, 0, 0, 0 },
  { 0x13, 0x000cca40, 0x000c005c, 0x0004005c, 0x00000000, 0, 0, 0, 0 },
  { 0x14, 0x000cca40, 0x000f21c0, 0x000721c0, 0x00000000, 0, 0, 0, 0 },
  { 0x15, 0x000cca40, 0x000f21c0, 0x000721c0, 0x00000000, 0, 0, 0, 0 },
  { 0x16, 0x000cca40, 0x000c7740, 0x00046420, 0x00000000, 0, 0, 0, 0 },
  { 0x17, 0x000cca40, 0x000c7740, 0x00046420, 0x00000000, 0, 0, 0, 0 },
  { 0x18, 0x000cca40, 0x000c7740, 0x00048a60, 0x00000000, 0, 0, 0, 0 },
  { 0x19, 0x000cca40, 0x000c7740, 0x00048a60, 0x00000000, 0, 0, 0, 0 },
  { 0x1a, 0x000cca40, 0x000c7740, 0x00048a60, 0x00000000, 0, 0, 0, 0 },
  { 0x1b, 0x000cca40, 0x000c7740, 0x00048a60, 0x00000000, 0, 0, 0, 0 },
  { 0x1c, 0x000cca40, 0x0005f4e9, 0xfffdf4e9, 0x00000000, 0, 0, 0, 0 },
  { 0x1d, 0x000cca40, 0x000d3007, 0x00052e4b, 0x00000000, 0, 0, 0, 0 },
  { 0x1e, 0x000e9e00, 0x000b05b0, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x1f, 0x000e9e00, 0x000c005c, 0x00031c72, 0x00000000, 0, 0, 0, 0 },
  { 0x20, 0x000cca40, 0x000a6f37, 0x00026f37, 0x00000000, 0, 0, 0, 0 },
  { 0x21, 0x000cca40, 0x000a6f37, 0x00026f37, 0x00000000, 0, 0, 0, 0 },
  { 0x22, 0x000cca40, 0x000c7740, 0x00046420, 0x00000000, 0, 0, 0, 0 },
  { 0x23, 0x000cca40, 0x000c7740, 0x00046420, 0x00000000, 0, 0, 0, 0 },
  { 0x24, 0x000cca40, 0x000cece4, 0x0004ece4, 0x00000000, 0, 0, 0, 0 },
  { 0x25, 0x000cca40, 0x000cece4, 0x0004ece4, 0x00000000, 0, 0, 0, 0 },
  { 0x26, 0x000cca40, 0x000c7740, 0x00046420, 0x00000000, 0, 0, 0, 0 },
  { 0x27, 0x000cca40, 0x000c7740, 0x00046420, 0x00000000, 0, 0, 0, 0 },
  { 0x28, 0x000cca40, 0x000a6f37, 0x00026f37, 0x00000000, 0, 0, 0, 0 },
  { 0x29, 0x000cca40, 0x000a6f37, 0x00026f37, 0x00000000, 0, 0, 0, 0 },
  { 0x2a, 0x000cca40, 0x000d3007, 0x00052e4b, 0x00000000, 0, 0, 0, 0 },
  { 0x2b, 0x000cca40, 0x000d3007, 0x00052e4b, 0x00000000, 0, 0, 0, 0 },
  { 0x2c, 0x000838e0, 0x000c005c, 0x0004005c, 0x00000000, 0, 0, 0, 0 },
  { 0x2d, 0x00049160, 0x000c005c, 0x0004005c, 0x00000000, 0, 0, 0, 0 },
  { 0x2e, 0x0003a780, 0x00097ff4, 0x00017ff4, 0x00000000, 0, 0, 0, 0 },
  { 0x2f, 0x00066520, 0x00097ff4, 0x00017ff4, 0x00000000, 0, 0, 0, 0 },
  { 0x30, 0x000a0ca0, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x31, 0x000be060, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x32, 0x000a0ca0, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x33, 0x000be060, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x34, 0x000cca40, 0x000d3007, 0x00052e4b, 0x00000000, 0, 0, 0, 0 },
  { 0x35, 0x000cca40, 0x000d3007, 0x00052e4b, 0x00000000, 0, 0, 0, 0 },
  { 0x36, 0x000cca40, 0x000b8e69, 0x00038e69, 0x00000000, 0, 0, 0, 0 },
  { 0x37, 0x000cca40, 0x000b8e69, 0x00038e69, 0x00000000, 0, 0, 0, 0 },
  { 0x38, 0x001071c0, 0x0005f4e9, 0xfffdf4e9, 0x00000000, 0, 0, 0, 0 },
  { 0x39, 0x001071c0, 0x0005f4e9, 0xfffdf4e9, 0x00000000, 0, 0, 0, 0 },
  { 0x3a, 0x001071c0, 0x0005f4e9, 0xfffdf4e9, 0x00000000, 0, 0, 0, 0 },
  { 0x3b, 0x001071c0, 0x0005f4e9, 0xfffdf4e9, 0x00000000, 0, 0, 0, 0 },
  { 0x3c, 0x001071c0, 0x0005f4e9, 0xfffdf4e9, 0x00000000, 0, 0, 0, 0 },
  { 0x3d, 0x001071c0, 0x0005f4e9, 0xfffdf4e9, 0x00000000, 0, 0, 0, 0 },
  { 0x3e, 0x000cca40, 0x00097ff4, 0x00017ff4, 0x00000000, 0, 0, 0, 0 },
  { 0x3f, 0x000cca40, 0x00097ff4, 0x00017ff4, 0x00000000, 0, 0, 0, 0 },
  { 0x40, 0x000922c0, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x41, 0x000b8e39, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x42, 0x000aaaab, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x43, 0x000b8e39, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x44, 0x000b8e39, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x45, 0x000aaaab, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x46, 0x0009c71c, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x47, 0x000c71c7, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x48, 0x000c71c7, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x49, 0x000638e4, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4a, 0x00080000, 0x000b05b0, 0x0002aaab, 0x00000000, 0, 0, 0, 0 },
  { 0x4b, 0x000c71c7, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4c, 0x000aaaab, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4d, 0x000f1c72, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4e, 0x000b8e39, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x4f, 0x000c71c7, 0x000b05b0, 0x0002aaab, 0x00000000, 0, 0, 0, 0 },
  { 0x50, 0x0009c71c, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x51, 0x000c71c7, 0x000b05b0, 0x0002aaab, 0x00000000, 0, 0, 0, 0 },
  { 0x52, 0x000b8e39, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x53, 0x0008e38e, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x54, 0x000aaaab, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x55, 0x000b8e39, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x56, 0x000b8e39, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x57, 0x00100000, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x58, 0x000b8e39, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x59, 0x000b8e39, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5a, 0x000aaaab, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5b, 0x001f0fc0, 0x000d3007, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5c, 0x00265ec0, 0x000d3007, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5d, 0x001f0fc0, 0x000d3007, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5e, 0x00265ec0, 0x000e6664, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x5f, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x60, 0x000922c0, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x61, 0x000a8190, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x62, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x63, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x64, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x65, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x66, 0x000be060, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x67, 0x000922c0, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x68, 0x000cca40, 0x00079357, 0xffff9357, 0x00000000, 0, 0, 0, 0 },
  { 0x69, 0x000af680, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x6a, 0x00074f00, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x6b, 0x000af680, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x6c, 0x000cca40, 0x0008d0c9, 0x0000d0c9, 0x00000000, 0, 0, 0, 0 },
  { 0x6d, 0x000cca40, 0x0008d0c9, 0x0000d0c9, 0x00000000, 0, 0, 0, 0 },
  { 0x6e, 0x000cca40, 0x00097ff4, 0x00017ff4, 0x00000000, 0, 0, 0, 0 },
  { 0x6f, 0x000cca40, 0x00097ff4, 0x00017ff4, 0x00000000, 0, 0, 0, 0 },
  { 0x70, 0x0003a780, 0x00097ff4, 0x00017ff4, 0x00000000, 0, 0, 0, 0 },
  { 0x71, 0x00066520, 0x00097ff4, 0x00017ff4, 0x00000000, 0, 0, 0, 0 },
  { 0x72, 0x000cca40, 0x00097ff4, 0x00017ff4, 0x00000000, 0, 0, 0, 0 },
  { 0x73, 0x000cca40, 0x0005f4e9, 0xfffdf4e9, 0x00000000, 0, 0, 0, 0 },
  { 0x74, 0x000cca40, 0x0007e639, 0xffffe639, 0x00000000, 0, 0, 0, 0 },
  { 0x75, 0x000cca40, 0x00097ff4, 0x00017ff4, 0x00000000, 0, 0, 0, 0 },
  { 0x76, 0x000cca40, 0x000c7740, 0x00048a60, 0x00000000, 0, 0, 0, 0 },
  { 0x77, 0x000cca40, 0x000c7740, 0x00048a60, 0x00000000, 0, 0, 0, 0 },
  { 0x78, 0x001071c0, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x79, 0x001071c0, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7a, 0x000cca40, 0x00097ff4, 0x00017ff4, 0x00000000, 0, 0, 0, 0 },
  { 0x7b, 0x000af680, 0x0006e38e, 0x00000000, 0x0000add4, 0, 0, 0, 0 },
  { 0x7c, 0x0008e38e, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7d, 0x0008e6b4, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7e, 0x0008e6b4, 0x000b05b0, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7f, 0x00070fcb, 0x0006e38e, 0x00000000, 0x00000000, 0, 0, 0, 0 }
};

void
msbm9_tables(TFM::Font*& _font, TFM::Dimension*& _dimension, TFM::Character*& _character)
{
  _font = &font;
  _dimension = dimension;
  _character = character;
}
