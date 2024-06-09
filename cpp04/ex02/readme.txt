





Pour rendre une class abstraite, on doit definir une fonction membre

comme purement virtuelle en ajoutant = 0;

cette syntaxe indique que cest une fonction virtuelle pure donc:
    - quil ny a pas dimplementation dans cette fonction.
    - que les class derives doivent fournir leur propre implementation


Destructeur Virtuel : Il est crucial d'inclure un destructeur virtuel dans la classe de base
pour s'assurer que le destructeur des classes dérivées est appelé lorsqu'un objet dérivé est supprimé
via un pointeur de type classe de base.