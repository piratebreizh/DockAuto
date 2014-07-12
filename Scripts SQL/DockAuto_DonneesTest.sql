USE dockautodb;

--
-- Contenu de la table 'entrepot'
--

INSERT INTO entrepot (ID_Entrepot, Nom_Entrepot, Longueur_Entrepot, Largeur_Entrepot) VALUES
(1, 'simple', 10, 10);

--
-- Contenu de la table 'equipe'
--

INSERT INTO equipe (ID_Equipe, Nom_Equipe) VALUES
(1, 'Equipe1');

--
-- Contenu de la table 'liste_taches'
--

INSERT INTO liste_taches (ID_Liste_Taches, Nom_Liste_Taches) VALUES
(1, 'Taches1');

--
-- Contenu de la table 'robot'
--

INSERT INTO robot (ID_Robot, Nom_Robot, Longueur_Robot, Largeur_Robot, Vitesse_Robot, Longueur_Capacite_De_Charge_Robot, Largeur_Capactite_De_Charge_Robot, Poids_Capacite_De_Charge_Robot, ID_Equipe) VALUES
(1, 'Robot1', 1, 1, 1, 1, 1, 1, 1),
(2, 'Robot2', 1, 1, 1, 1, 1, 1, 1);

--
-- Contenu de la table 'simulation'
--

INSERT INTO simulation (ID_Simulation, Nom_Simulation, ID_Entrepot, ID_Equipe, ID_Liste_Taches) VALUES
(1, 'Simulation1', 1, 1, 1);

--
-- Contenu de la table 'tache'
--

INSERT INTO tache (ID_Tache, Poids_Tache, Depart_X, Depart_Y, Arrive_X, Arrive_Y, ID_Liste_Taches, ID_Robot) VALUES
(1, 1, 2, 1, 0, 1, 1, 1),
(2, 1, 9, 1, 7, 1, 1, 2);

--
-- Contenu de la table 'tile'
--

INSERT INTO tile (ID_Tile, X, Y, ID_Type, ID_Entrepot) VALUES
(1, 0, 1, -3, 1),
(2, 1, 8, -5, 1),
(3, 2, 1, -3, 1),
(4, 7, 1, -3, 1),
(5, 8, 9, -5, 1),
(6, 9, 1, -3, 1);
