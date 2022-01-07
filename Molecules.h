#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Atom
{
public:
	Atom(std::string name, float mass) : name(name), mass(mass) {}

	std::string GetName() const { return name; }
	float GetMass() const { return mass; }

private:
	std::string name;
	float mass;
};

class Molecule
{
public:
	Molecule() {}

	float const GetMass();
	void AddAtom(Atom *a) { atoms.push_back(a); }

	std::vector<Atom*> atoms;
};

class Gaz
{
public:
	Gaz() {}
	float const GetMass();
	void AddMolecule(Molecule* m) { molecules.push_back(m); }

	std::vector<Molecule*> molecules;

};

class H2O : public Molecule
{
public:
	H2O();
};

int GetDistinctsAtomsCount(const Gaz&);