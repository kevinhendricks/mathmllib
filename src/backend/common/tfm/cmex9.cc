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
"CMEX",

  0xec,
  "TeX math extension",
  0x00900000,
  0x7ac0d369,
  13,
  128
};

static TFM::Dimension dimension[] = {
  { 0x01, "slant", 0x00000000 },
  { 0x02, "space", 0x00000000 },
  { 0x03, "space_stretch", 0x00000000 },
  { 0x04, "space_shrink", 0x00000000 },
  { 0x05, "x_height", 0x0006e38e },
  { 0x06, "quad", 0x001071c0 },
  { 0x07, "extra_space", 0x00000000 },
  { 0x08, "default_rule_thickness", 0x0000acf2 },
  { 0x09, "big_op_spacing1", 0x0001c71c },
  { 0x0a, "big_op_spacing2", 0x0002aaab },
  { 0x0b, "big_op_spacing3", 0x00033334 },
  { 0x0c, "big_op_spacing4", 0x0009add4 },
  { 0x0d, "big_op_spacing5", 0x0001c71c }
};



static TFM::Character character[] = {
  { 0x00, 0x00078977, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x01, 0x00078977, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x02, 0x0006da10, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x03, 0x0006da10, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x04, 0x0007c3f0, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x05, 0x0007c3f0, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x06, 0x0007c3f0, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x07, 0x0007c3f0, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x08, 0x000997b2, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x09, 0x000997b2, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x0a, 0x0007c3f2, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x0b, 0x0007c3f2, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x0c, 0x00057b40, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 },
  { 0x0d, 0x000922c0, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 },
  { 0x0e, 0x0009804c, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x0f, 0x0009804c, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x10, 0x0009d227, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x11, 0x0009d227, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x12, 0x000c1ad7, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x13, 0x000c1ad7, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x14, 0x0008add0, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x15, 0x0008add0, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x16, 0x000997b0, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x17, 0x000997b0, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x18, 0x000997b0, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x19, 0x000997b0, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x1a, 0x000c5552, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x1b, 0x000c5552, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x1c, 0x000c5552, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x1d, 0x000c5552, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x1e, 0x00112cdb, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x1f, 0x00112cdb, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x20, 0x000d04b7, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x21, 0x000d04b7, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x22, 0x000997b0, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x23, 0x000997b0, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x24, 0x000a8190, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x25, 0x000a8190, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x26, 0x000a8190, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x27, 0x000a8190, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x28, 0x000d3f30, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x29, 0x000d3f30, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x2a, 0x000d3f30, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x2b, 0x000d3f30, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x2c, 0x00150320, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x2d, 0x00150320, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x2e, 0x000d5694, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x2f, 0x000d5694, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x30, 0x000e6387, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x31, 0x000e6387, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x32, 0x000af680, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x33, 0x000af680, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x34, 0x000af680, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x35, 0x000af680, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x36, 0x000af680, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 },
  { 0x37, 0x000af680, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 },
  { 0x38, 0x000e9e00, 0x00000000, 0x000e6670, 0x00000000, 0, 0, 0, 0 },
  { 0x39, 0x000e9e00, 0x00000000, 0x000e6670, 0x00000000, 0, 0, 0, 0 },
  { 0x3a, 0x000e9e00, 0x00000000, 0x000e6670, 0x00000000, 0, 0, 0, 0 },
  { 0x3b, 0x000e9e00, 0x00000000, 0x000e6670, 0x00000000, 0, 0, 0, 0 },
  { 0x3c, 0x000e9e00, 0x00000000, 0x001ccce0, 0x00000000, 0, 0, 0, 0 },
  { 0x3d, 0x000e9e00, 0x00000000, 0x001ccce0, 0x00000000, 0, 0, 0, 0 },
  { 0x3e, 0x000e9e00, 0x00000000, 0x0004ccd0, 0x00000000, 0, 0, 0, 0 },
  { 0x3f, 0x000af680, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 },
  { 0x40, 0x000e6387, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x41, 0x000e6387, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x42, 0x000e6387, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 },
  { 0x43, 0x000e6387, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 },
  { 0x44, 0x000a0ca0, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x45, 0x000a0ca0, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x46, 0x000db420, 0x00000000, 0x0010000e, 0x00000000, 0, 0, 0, 0 },
  { 0x47, 0x00124580, 0x0001999b, 0x0018000c, 0x00000000, 0, 0, 0, 0 },
  { 0x48, 0x0007c3f0, 0x00000000, 0x0011c729, 0x00033290, 0, 0, 0, 0 },
  { 0x49, 0x000922c0, 0x00000000, 0x00238e52, 0x00074f00, 0, 0, 0, 0 },
  { 0x4a, 0x00124580, 0x00000000, 0x0010000e, 0x00000000, 0, 0, 0, 0 },
  { 0x4b, 0x0018d965, 0x0001999b, 0x0018000c, 0x00000000, 0, 0, 0, 0 },
  { 0x4c, 0x00124580, 0x00000000, 0x0010000e, 0x00000000, 0, 0, 0, 0 },
  { 0x4d, 0x0018d965, 0x0001999b, 0x0018000c, 0x00000000, 0, 0, 0, 0 },
  { 0x4e, 0x00124580, 0x00000000, 0x0010000e, 0x00000000, 0, 0, 0, 0 },
  { 0x4f, 0x0018d965, 0x0001999b, 0x0018000c, 0x00000000, 0, 0, 0, 0 },
  { 0x50, 0x00115ba0, 0x00000000, 0x0010000e, 0x00000000, 0, 0, 0, 0 },
  { 0x51, 0x000f87e0, 0x00000000, 0x0010000e, 0x00000000, 0, 0, 0, 0 },
  { 0x52, 0x0007c3f0, 0x00000000, 0x0011c729, 0x00033290, 0, 0, 0, 0 },
  { 0x53, 0x000db420, 0x00000000, 0x0010000e, 0x00000000, 0, 0, 0, 0 },
  { 0x54, 0x000db420, 0x00000000, 0x0010000e, 0x00000000, 0, 0, 0, 0 },
  { 0x55, 0x000db420, 0x00000000, 0x0010000e, 0x00000000, 0, 0, 0, 0 },
  { 0x56, 0x000db420, 0x00000000, 0x0010000e, 0x00000000, 0, 0, 0, 0 },
  { 0x57, 0x000db420, 0x00000000, 0x0010000e, 0x00000000, 0, 0, 0, 0 },
  { 0x58, 0x0017c0c0, 0x0001999b, 0x0018000c, 0x00000000, 0, 0, 0, 0 },
  { 0x59, 0x00150320, 0x0001999b, 0x0018000c, 0x00000000, 0, 0, 0, 0 },
  { 0x5a, 0x000922c0, 0x00000000, 0x00238e52, 0x00074f00, 0, 0, 0, 0 },
  { 0x5b, 0x00124580, 0x0001999b, 0x0018000c, 0x00000000, 0, 0, 0, 0 },
  { 0x5c, 0x00124580, 0x0001999b, 0x0018000c, 0x00000000, 0, 0, 0, 0 },
  { 0x5d, 0x00124580, 0x0001999b, 0x0018000c, 0x00000000, 0, 0, 0, 0 },
  { 0x5e, 0x00124580, 0x0001999b, 0x0018000c, 0x00000000, 0, 0, 0, 0 },
  { 0x5f, 0x00124580, 0x0001999b, 0x0018000c, 0x00000000, 0, 0, 0, 0 },
  { 0x60, 0x000f87e0, 0x00000000, 0x0010000e, 0x00000000, 0, 0, 0, 0 },
  { 0x61, 0x00150320, 0x0001999b, 0x0018000c, 0x00000000, 0, 0, 0, 0 },
  { 0x62, 0x000922c0, 0x000b8e39, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x63, 0x001071c0, 0x000c0000, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x64, 0x0017c0c0, 0x000c0000, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x65, 0x000922c0, 0x000b8e39, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x66, 0x001071c0, 0x000c0000, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x67, 0x0017c0c0, 0x000c0000, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x68, 0x0007c3f0, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x69, 0x0007c3f0, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x6a, 0x0008add0, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x6b, 0x0008add0, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x6c, 0x0008add0, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x6d, 0x0008add0, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x6e, 0x000af680, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x6f, 0x000af680, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x70, 0x001071c0, 0x0000acf2, 0x0012864e, 0x00000000, 0, 0, 0, 0 },
  { 0x71, 0x001071c0, 0x0000acf2, 0x001c1fee, 0x00000000, 0, 0, 0, 0 },
  { 0x72, 0x001071c0, 0x0000acf2, 0x0025b98e, 0x00000000, 0, 0, 0, 0 },
  { 0x73, 0x001071c0, 0x0000acf2, 0x002f532e, 0x00000000, 0, 0, 0, 0 },
  { 0x74, 0x00115ba0, 0x00000000, 0x001ccce0, 0x00000000, 0, 0, 0, 0 },
  { 0x75, 0x00115ba0, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 },
  { 0x76, 0x00115ba0, 0x0000acf2, 0x0008ecae, 0x00000000, 0, 0, 0, 0 },
  { 0x77, 0x000cca40, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 },
  { 0x78, 0x000af680, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 },
  { 0x79, 0x000af680, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 },
  { 0x7a, 0x00073339, 0x000206d5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7b, 0x00073339, 0x000206d5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7c, 0x00073339, 0x000206d5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7d, 0x00073339, 0x000206d5, 0x00000000, 0x00000000, 0, 0, 0, 0 },
  { 0x7e, 0x000cca40, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 },
  { 0x7f, 0x000cca40, 0x00000000, 0x000999a0, 0x00000000, 0, 0, 0, 0 }
};

void
cmex9_tables(TFM::Font*& _font, TFM::Dimension*& _dimension, TFM::Character*& _character)
{
  _font = &font;
  _dimension = dimension;
  _character = character;
}
