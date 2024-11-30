
void Insererprecesseur(etat nouveauetat, liste *pliste,noeud *nprecesseur){
    // "nprecesseur": c'est un pointeur sur le noeud parent du notre arbre
    // cette fonction cree un noeud ayant l'etat "nouveauetat" et un precesseur "nprecesseur" et l'insere sur la file "pliste"
    //Dans une pile le suivant est celui qui le suit dans la liste
    liste L1=*pliste;
    noeud *nouveaunoeaud=malloc(sizeof(noeud));//pointeur pour que la variable de type noeud ne soit pas supprimer
    nouveaunoeaud->Etat=nouveauetat;
    nouveaunoeaud->suivant=NULL;
    nouveaunoeaud->precesseur=nprecesseur;
    if (L1.debut==NULL)
    {L1.debut=nouveaunoeaud;
    L1.fin=nouveaunoeaud;}
    else{(L1.fin)->suivant=nouveaunoeaud;
    (L1.fin)=nouveaunoeaud;

    }
    *pliste=L1;
}

void Inserer(etat nouveauetat, liste *pliste){//inserer un noeud sur une file
    noeud *nprecesseur=NULL;
    Insererprecesseur(nouveauetat,pliste,nprecesseur);
}

int Vide(liste listeNoeuds){
return (listeNoeuds.debut==NULL);
}

noeud* Extraire (liste* listenoeuds){// extraire un noeud du file"listenoeus"
    noeud * temp;
    if(listenoeuds->debut== listenoeuds->fin)listenoeuds->fin=NULL;
   temp=(listenoeuds->debut);
   listenoeuds->debut=temp->suivant;

      return temp;
}

int etatSolution (etat etatCourant,etat etatfinal){
    return (etatCourant.x == etatfinal.x && etatCourant.y == etatfinal.y );}

void genereSuccesseurs(noeud* noeudCourantp) {//la premiere cruche est de 4L et le deuxieme est de 3L
void regle1(noeud* noeudCourant){//remplir  la premiere cruche 4L
    etat etatCourant=noeudCourant->Etat;
    if (etatCourant.x<4 ){
            etat nouveauetat;
            nouveauetat.x=4;
            nouveauetat.y=etatCourant.y;
            Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
    }
}
void regle2(noeud* noeudCourant){//remplir  la deuxieme cruche 3L
        etat etatCourant=noeudCourant->Etat;
    if (etatCourant.y<3 ){
            etat nouveauetat;
            nouveauetat.y=3;
            nouveauetat.x=etatCourant.x;
            Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
    }
}
void regle3(noeud* noeudCourant){//verser  la premiere cruche dans la deuxieme
        etat etatCourant=noeudCourant->Etat;
    if (etatCourant.x>0 && etatCourant.y<3){
            etat nouveauetat;

            if (etatCourant.x+etatCourant.y>3){
            nouveauetat.y=3;
            nouveauetat.x=etatCourant.x-(3-etatCourant.y);}
            else{
            nouveauetat.y=etatCourant.x+etatCourant.y;
            nouveauetat.x=0;
            }
            Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
    }
}
void regle4(noeud* noeudCourant){//verser  la deuxieme cruche dans la premiere
        etat etatCourant=noeudCourant->Etat;
    if (etatCourant.y>0 && etatCourant.x<4){
            etat nouveauetat;
            if (etatCourant.x+etatCourant.y>4){
            nouveauetat.x=4;
            nouveauetat.y=etatCourant.y-(4-etatCourant.x);}
            else{
            nouveauetat.x=etatCourant.x+etatCourant.y;
            nouveauetat.y=0;
            }
            Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
    }
}
void regle5(noeud* noeudCourant){//vider  la premiere cruche 4L
        etat etatCourant=noeudCourant->Etat;
    if (etatCourant.x>0 ){
            etat nouveauetat;
            nouveauetat.x=0;
            nouveauetat.y=etatCourant.y;
            Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
    }
}
void regle6(noeud* noeudCourant){//vider  la deuxieme cruche 3L
        etat etatCourant=noeudCourant->Etat;
    if (etatCourant.y>0 ){
            etat nouveauetat;
            nouveauetat.y=0;
            nouveauetat.x=etatCourant.x;
            Insererprecesseur(nouveauetat, &listeNoeuds,noeudCourant);
    }
}
regle1(noeudCourantp);
regle2(noeudCourantp);
regle3(noeudCourantp);
regle4(noeudCourantp);
regle5(noeudCourantp);
regle6(noeudCourantp);
}

int Appartient (etat etatCourant , liste NoeudsDejaTraites){
noeud* p=NoeudsDejaTraites.debut;
  while(p!=NULL){
    if (p->Etat.x==etatCourant.x && p->Etat.y==etatCourant.y) return 1;
    p=p->suivant;
  }
  return 0;
}

int RechercheLargeur(etat etatInitial ,etat etatfinal , void genereSuccesseurs()){

liste NoeudsDejaTraites;
etat etatCourant;
noeud* noeudCourantp;
listeNoeuds.debut =listeNoeuds.fin =NULL;
Inserer(etatInitial,&listeNoeuds);
NoeudsDejaTraites.debut=NoeudsDejaTraites.fin =NULL;
while(!Vide (listeNoeuds))
      {
         noeudCourantp=Extraire(&listeNoeuds);
         etatCourant=noeudCourantp->Etat;
            n++;


if (etatSolution (etatCourant ,etatfinal))
{
    printf("\nSucess ! arret sur le noeud :(%d,%d)\nNombre de noeuds explores :%d\n",etatCourant.x,etatCourant.y,n);
    afficher(noeudCourantp);//affiche le chemin des preccesseurs depuis la liste NoeudsDejaTraites
    return (0);
}
else if(!Appartient (etatCourant ,NoeudsDejaTraites)){
        genereSuccesseurs(noeudCourantp);//stocke les preccesseur
        Inserer(etatCourant, &NoeudsDejaTraites);//Inserer(noeudCourantp, &NoeudsDejaTraites);
        }

    }
    puts("\nPas de solution");

}

void afficher (noeud* noeudCourantp){
noeud* p=noeudCourantp;
printf("le chemin pour atteindre le noeud (%d,%d) est comme suit :",(p->Etat.x),p->Etat.y);
  while(p!=NULL){
    printf("-(%d,%d)-",(p->Etat.x),p->Etat.y) ;
    p=p->precesseur;
  }
}

void Insererprecesseurprofond(etat nouveauetat, liste *pliste,noeud *nprecesseur){
     // cette fonction cree un noeud ayant l'etat "nouveauetat" et un precesseur "nprecesseur" et l'insere sur la file "pliste"
    //Dans une pile le suivant est celui qui le precede dans la liste
    liste L1=*pliste;
    noeud *nouveaunoeaud=malloc(sizeof(noeud));//pointeur pour que la variable de type noeud ne soit pas supprimer
    nouveaunoeaud->Etat=nouveauetat;
    nouveaunoeaud->suivant=NULL;
    nouveaunoeaud->precesseur=nprecesseur;
    if (L1.fin==NULL)
    {L1.fin=nouveaunoeaud;}
    else{nouveaunoeaud->suivant=(L1.fin);
    (L1.fin)=nouveaunoeaud;
    }
    *pliste=L1;
}

void Insererprofond(etat nouveauetat, liste *pliste){
    noeud *nprecesseur=NULL;
    Insererprecesseurprofond(nouveauetat,pliste,nprecesseur);
}

noeud* Extraireprofond(liste* listenoeuds){
    noeud * temp;
   temp=(listenoeuds->fin);
   listenoeuds->fin=temp->suivant;

      return temp;
}

void genereSuccesseursprofond(noeud* noeudCourantp) {//la premiere cruche est de 4L et le deuxieme est de 3L
void regle1(noeud* noeudCourant){//remplir  la premiere cruche 4L
    etat etatCourant=noeudCourant->Etat;
    if (etatCourant.x<4 ){
            etat nouveauetat;
            nouveauetat.x=4;
            nouveauetat.y=etatCourant.y;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
    }
}
void regle2(noeud* noeudCourant){//remplir  la deuxieme cruche 3L
        etat etatCourant=noeudCourant->Etat;
    if (etatCourant.y<3 ){
            etat nouveauetat;
            nouveauetat.y=3;
            nouveauetat.x=etatCourant.x;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
    }
}
void regle3(noeud* noeudCourant){//verser  la premiere cruche dans la deuxieme
        etat etatCourant=noeudCourant->Etat;
    if (etatCourant.x>0 && etatCourant.y<3){
            etat nouveauetat;

            if (etatCourant.x+etatCourant.y>3){
            nouveauetat.y=3;
            nouveauetat.x=etatCourant.x-(3-etatCourant.y);}
            else{
            nouveauetat.y=etatCourant.x+etatCourant.y;
            nouveauetat.x=0;
            }
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
    }
}
void regle4(noeud* noeudCourant){//verser  la deuxieme cruche dans la premiere
        etat etatCourant=noeudCourant->Etat;
    if (etatCourant.y>0 && etatCourant.x<4){
            etat nouveauetat;
            if (etatCourant.x+etatCourant.y>4){
            nouveauetat.x=4;
            nouveauetat.y=etatCourant.y-(4-etatCourant.x);}
            else{
            nouveauetat.x=etatCourant.x+etatCourant.y;
            nouveauetat.y=0;
            }
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
    }
}
void regle5(noeud* noeudCourant){//vider  la premiere cruche 4L
        etat etatCourant=noeudCourant->Etat;
    if (etatCourant.x>0 ){
            etat nouveauetat;
            nouveauetat.x=0;
            nouveauetat.y=etatCourant.y;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
    }
}
void regle6(noeud* noeudCourant){//vider  la deuxieme cruche 3L
        etat etatCourant=noeudCourant->Etat;
    if (etatCourant.y>0 ){
            etat nouveauetat;
            nouveauetat.y=0;
            nouveauetat.x=etatCourant.x;
            Insererprecesseurprofond(nouveauetat, &listeNoeuds,noeudCourant);
    }
}
regle1(noeudCourantp);
regle2(noeudCourantp);
regle3(noeudCourantp);
regle4(noeudCourantp);
regle5(noeudCourantp);
regle6(noeudCourantp);
}

int Appartientprofond (etat etatCourant , liste NoeudsDejaTraites){
noeud* p=NoeudsDejaTraites.fin;
  while(p!=NULL){
    if (p->Etat.x==etatCourant.x && p->Etat.y==etatCourant.y) return 1;
    p=p->suivant;
  }
  return 0;
}

int Videprofond(liste listeNoeuds){
return (listeNoeuds.fin==NULL);
}

int Rechercheprofondeur(etat etatInitial ,etat etatfinal , void genereSuccesseursprofond()){
liste NoeudsDejaTraites;
etat etatCourant;
noeud* noeudCourantp;
listeNoeuds.debut =listeNoeuds.fin =NULL;
Insererprofond(etatInitial,&listeNoeuds);
NoeudsDejaTraites.debut=NoeudsDejaTraites.fin =NULL;
while(!Videprofond (listeNoeuds))
      {
         noeudCourantp=Extraireprofond(&listeNoeuds);
         etatCourant=noeudCourantp->Etat;
            n++;
if (etatSolution (etatCourant ,etatfinal))
{
    printf("\nSucess ! arret sur le noeud :(%d,%d)\nNombre de noeuds explores :%d\n",etatCourant.x,etatCourant.y,n);
    afficher(noeudCourantp);//affiche le chemin des preccesseurs depuis la liste NoeudsDejaTraites
    return (0);
}
else if(!Appartientprofond (etatCourant ,NoeudsDejaTraites)){
        genereSuccesseursprofond(noeudCourantp);//stocke les preccesseur
        Insererprofond(etatCourant, &NoeudsDejaTraites);//Inserer(noeudCourantp, &NoeudsDejaTraites);
        }

    }
    puts("\nPas de solution");

}

