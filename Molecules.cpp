#include "Molecules.h"

float const Molecule::GetMass()
{
	float sum = 0;
	for (Atom *a : atoms) { sum += a->GetMass(); }
	return sum;
}

float const Gaz::GetMass()
{
	float sum = 0;
	for (Molecule* m : molecules) { sum += m->GetMass(); }
	return sum;
}

H2O::H2O()
{
	AddAtom(new Atom("H", 1));
	AddAtom(new Atom("H", 1));
	AddAtom(new Atom("O", 8));
}

int GetDistinctsAtomsCount(const Gaz& g)
{
	std::vector<Atom*> atoms;

	// Get every atom from gaz's molecules
	for (Molecule* m : g.molecules)
	{
		atoms.insert(atoms.end(), m->atoms.begin(), m->atoms.end());
	}

	// Sort the atoms to use std::unique
	std::sort(atoms.begin(), atoms.end(), [](const Atom* lhs, const Atom* rhs) { return lhs->GetMass() < rhs->GetMass(); });

	// Erase duplicates by atom mass
	atoms.erase(std::unique(atoms.begin(), atoms.end(), [](const Atom* lhs, const Atom* rhs) { return lhs->GetMass() == rhs->GetMass(); }), atoms.end());

	return atoms.size();
}