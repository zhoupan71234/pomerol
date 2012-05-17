//
// This file is a part of pomerol - a scientific ED code for obtaining 
// properties of a Hubbard model on a finite-size lattice 
//
// Copyright (C) 2010-2012 Andrey Antipov <antipov@ct-qmc.org>
// Copyright (C) 2010-2012 Igor Krivenko <igor@shg.ru>
//
// pomerol is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// pomerol is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with pomerol.  If not, see <http://www.gnu.org/licenses/>.

/** \file tests/IndexTerm.cpp
** \brief Test of the IndexHamiltonian::Term.
**
** \author Andrey Antipov (Andrey.E.Antipov@gmail.com)
*/

#include "Misc.h"
#include "Logger.h"
#include "Index.h"
#include "IndexClassification.h"
#include "IndexHamiltonian.h"
#include <boost/shared_ptr.hpp>

using namespace Pomerol;

int main(int argc, char* argv[])
{
  /* Test of IndexHamiltonian::Term*/
  Log.setDebugging(true);
  bool Seq[4] = {0,0,1,0};
  ParticleIndex Ind[] = {1,2,2,4};
  std::vector<bool> seq_v(Seq, Seq+4);
  std::vector<ParticleIndex> ind_v(Ind, Ind+4);
  IndexHamiltonian::Term IT1(4, seq_v, ind_v, 1.0);
  INFO("Created IndexHamiltonian::Term" << IT1);
  INFO("Rearranging it to normal order");
  boost::shared_ptr<std::list<IndexHamiltonian::Term*> > out_terms=IT1.makeNormalOrder();
  INFO("Received " << IT1);
  INFO(out_terms->size() << " additional terms emerged : ");     
  for (std::list<IndexHamiltonian::Term*>::const_iterator it1=out_terms->begin(); it1!=out_terms->end(); ++it1) DEBUG(**it1);
  /* end of test of IndexHamiltonian::Term */

  return EXIT_SUCCESS;
}

