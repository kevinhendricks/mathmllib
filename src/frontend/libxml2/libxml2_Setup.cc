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

#include <config.h>

#include "AbstractLogger.hh"
#include "libxml2_Setup.hh"
#include "libxml2_Model.hh"
#include "TemplateSetup.hh"

bool
libxml2_Setup::loadOperatorDictionary(const class AbstractLogger& logger,
				      MathMLOperatorDictionary& dictionary, const String& path)
{
  return TemplateSetup<libxml2_Model>::load<MathMLOperatorDictionary, true>(logger, dictionary,
									    "operator dictionary",
									    "dictionary", path);
}

bool
libxml2_Setup::loadConfiguration(const class AbstractLogger& logger,
				 Configuration& conf, const String& path)
{
  return TemplateSetup<libxml2_Model>::load<Configuration, false>(logger, conf,
								  "configuration",
								  "math-engine-configuration", path);
}

