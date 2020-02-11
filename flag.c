-	Aligner à gauche le résultat selon la largeur de champ donnée.	Aligner à droite.
+	Utilisez un signe (+ ou -) pour préfixer la valeur de sortie s’il s’agit d’un type signé.	Le signe apparaît uniquement pour les valeurs signées négatives (-).
0	Si width est préfixé par 0, des zéros non significatifs sont ajoutés jusqu’à ce que la largeur minimale soit atteinte. Si 0 et - apparaissent, le 0 est ignoré. Si 0 est spécifié pour un format entier (i, u, x, X, o, d) et qu’une spécification de précision est également présente (par exemple, %04.d), le 0 est ignoré. Si 0 est spécifié pour le format à virgule flottante a ou A, des zéros non significatifs sont ajoutés en préfixe à la mantisse, après le préfixe 0x ou 0X.	Aucun remplissage.
espace (' ')	Utilisez un espace pour préfixer la valeur de sortie si elle est signée et positive. L’espace est ignoré si l’espace et des indicateurs + apparaissent.	Aucun espace ne s’affiche.
#	Quand il est utilisé avec le format o, x ou X, l’indicateur # utilise 0, 0x ou 0X, respectivement, pour préfixer une valeur de sortie différente de zéro.	Aucun espace ne s’affiche.

*

The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.
