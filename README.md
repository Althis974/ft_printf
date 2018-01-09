# FT_PRINTF

# Sujet

• Vous devez recoder la fonction printf de la librairie C.
• Votre fonction s’appelera ft_printf et sera prototypée de la même façon que
printf.
• Vous ne ferez pas la gestion de buffer présente dans la fonction printf de la librairie
C.
• Vous devez gérer les conversions suivantes : sSpdDioOuUxXcC
• Vous devez gérer le %%
• Vous devez gérer les flags #0-+ et espace
• Vous devez gérer la taille minimum du champ
• Vous devez gérer la précision
• Vous devez gérer les flags hh h l ll j z

# Sujet - Partie bonus

  Voici quelques idées de bonus intéressants à réaliser, voire même utiles. Vous pouvez
évidemment ajouter des bonus de votre invention, qui seront évalués à la discrétion de
vos correcteurs.
• Gestion de conversions plus délicates : eE, fF, gG, aA, n.
• Gestion de flags plus delicats : *, $, L, ’ .
• Gestion de flags non existants : %b pour afficher en binaire, %r pour afficher une
chaine avec des caractères non imprimables, %k pour afficher une date à un format
ISO quelconque, etc.
• Gestion de modifieurs pour gérer les couleurs, les fd ou des choses fun comme ça :)
printf("Le fichier {cyan}%s{eoc} contient : {red}%s{eoc}", filename, str) ;
