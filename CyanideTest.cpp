#include <iostream>
#include <cassert>
#include "Molecules.h"

int main()
{
    // Part 1
    std::cout << "PART 1" << std::endl;
    {
        Atom* h = new Atom("H", 1);
        std::cout << "Hydrogen: " << h->GetName() << " " << h->GetMass() << std::endl;

        Atom* p0 = new Atom("O", 8);
        H2O h2o;

        Molecule m;
        m.AddAtom(h);
        m.AddAtom(h);
        m.AddAtom(p0);

        if (m.GetMass() == h2o.GetMass())
            std::cout << "M and H2O are equal." << std::endl;

        delete h, p0;
    }

    std::cout << std::endl;

    // Part 2
    std::cout << "PART 2" << std::endl;
    {
        std::vector<Gaz*> gazArray;

        Atom* h = new Atom("H", 1);
        Atom* o = new Atom("O", 8);
        Atom* s = new Atom("S", 16);
        Atom* i = new Atom("I", 53);

        Molecule* m1 = new Molecule();
        Molecule* m2 = new Molecule();
        Molecule* m3 = new Molecule();

        m1->AddAtom(h); m1->AddAtom(h); m1->AddAtom(o);
        m2->AddAtom(s); m2->AddAtom(i);
        m3->AddAtom(s); m3->AddAtom(o); m3->AddAtom(o);

        Gaz* g1 = new Gaz(); // Distincts : S, I, O
        Gaz* g2 = new Gaz(); // Distincts : H, O
        Gaz* g3 = new Gaz(); // Distincts : H, O, S

        g1->AddMolecule(m2); g1->AddMolecule(m3);
        g2->AddMolecule(m1); g2->AddMolecule(m1);
        g3->AddMolecule(m1); g3->AddMolecule(m3);

        gazArray.push_back(g1); gazArray.push_back(g2); gazArray.push_back(g3);

        std::cout << "Gaz 1 : S2O2I (Distincts: S, O, I)" << std::endl;
        std::cout << "Gaz 2 : H4O2 (Distincts: H, O)" << std::endl;
        std::cout << "Gaz 3 : H2O3S (Distincts: H, O, S)" << std::endl;

        std::cout << "Sorting by distinct atoms count" << std::endl;
        // ### Sorting ###
        std::cout << "\tBefore sorting" << std::endl << "\t";
        for (Gaz* g : gazArray)
        {
            std::cout << GetDistinctsAtomsCount(*g) << " ";
        }

        std::sort(gazArray.begin(), gazArray.end(), [](const Gaz* lhs, const Gaz* rhs) { return GetDistinctsAtomsCount(*lhs) < GetDistinctsAtomsCount(*rhs); });

        std::cout << std::endl << "\tAfter sorting" << std::endl << "\t";
        for (Gaz* g : gazArray)
        {
            std::cout << GetDistinctsAtomsCount(*g) << " ";
        }
        std::cout << std::endl;
        // ###############

        delete h, o, s, i;
        delete m1, m2, m3;
        delete g1, g2, g3;
    }

    system("PAUSE");
}