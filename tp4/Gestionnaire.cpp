#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

void Gestionnaire::afficherLesProfils() const
{
	for (int i = 0; i < usagers_.size(); i++)
	{
		usagers_[i]->afficherProfil();
	}
}

double Gestionnaire::obtenirChiffreAffaires() const
{
	double chiffreAffaire = 0;
	for (int i = 0; i < usagers_.size(); i++)
	{	if(typeid(usagers_[i])!=typeid(Fournisseur))
		chiffreAffaire += usagers_[i]->obtenirTotalAPayer();
	} 
	return chiffreAffaire;
}

void Gestionnaire::ajouterUsager(Usager *usager)
{
	bool existedeja = false;
	for (int i = 0; i < usagers_.size(); i++)
	{
		if (usagers_[i] == usager)
		{
			existedeja = true; // verifie que l'usager ne figure pas deja dans la liste d'usager
		}
	}
	if (existedeja = false)// s'il n'existe pas, on l'ajoute.
	{
		usagers_.push_back(usager);
	}
	
}

void Gestionnaire::reinitialiser()
{
    // TODO
	for (int i = 0; i < usagers_.size(); i++)
	{
		usagers_[i]->reinitialiser();
	}
}

void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
	if (montant>produit->obtenirPrix())
	{
		produit->mettreAJourEnchere(client, montant);
	}
}
