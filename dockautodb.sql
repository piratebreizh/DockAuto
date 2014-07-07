-- phpMyAdmin SQL Dump
-- version 4.0.4
-- http://www.phpmyadmin.net
--
-- Client: localhost
-- Généré le: Lun 23 Juin 2014 à 14:06
-- Version du serveur: 5.6.12-log
-- Version de PHP: 5.4.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données: `DockAutodb`
--

DROP DATABASE IF EXISTS `DockAutodb`;


CREATE DATABASE IF NOT EXISTS `DockAutodb` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `DockAutodb`;

-- --------------------------------------------------------

--
-- Structure de la table `armoire`
--

CREATE TABLE IF NOT EXISTS `armoire` (
  `ID_Armoire` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Clé de la table',
  `Nom` varchar(50) NOT NULL COMMENT 'Nom de l''armoire',
  `ID_Entrepot` int(11) NOT NULL COMMENT 'Clé de l''entrepôt',
  PRIMARY KEY (`ID_Armoire`),
  UNIQUE KEY `ID_Armoire` (`ID_Armoire`),
  KEY `ID_Entrepot` (`ID_Entrepot`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Armoire d''un entrepôt';

-- --------------------------------------------------------

--
-- Structure de la table `cargaison`
--

CREATE TABLE IF NOT EXISTS `cargaison` (
  `ID_Cargaison` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Clé de la table',
  `Nom` varchar(45) NOT NULL COMMENT 'Nom de la cargaison',
  `ID_Armoire` int(11) NOT NULL COMMENT 'Clé de l''armoire',
  PRIMARY KEY (`ID_Cargaison`),
  UNIQUE KEY `ID_Cargaison` (`ID_Cargaison`),
  KEY `ID_Armoire` (`ID_Armoire`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Cargaison';

-- --------------------------------------------------------

--
-- Structure de la table `entrepot`
--

CREATE TABLE IF NOT EXISTS `entrepot` (
  `ID_Entrepot` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Clé de la table',
  `Nom_Entrepot` varchar(100) NOT NULL COMMENT 'Nom de l''entrepôt',
  `Longueur_Entrepot` double NOT NULL COMMENT 'Longueur de l''entrepot',
  `Largeur_Entrepot` double NOT NULL COMMENT 'Largeur de l''entrepot',
  PRIMARY KEY (`ID_Entrepot`),
  UNIQUE KEY `ID_Entrepot` (`ID_Entrepot`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Entrepôt gérer par un tableau en 2d';

-- --------------------------------------------------------


-- --------------------------------------------------------

--
-- Structure de la table `liste_taches_robot`
--

CREATE TABLE IF NOT EXISTS `liste_taches` (
  `ID_Liste_Taches` int(11) NOT NULL,
  `Nom_Liste_Taches` varchar(100),
   PRIMARY KEY (`ID_Liste_Taches`),
  KEY `ID_Liste_Taches` (`ID_Liste_Taches`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Liste des tâches d''un robot';

-- --------------------------------------------------------

--
-- Structure de la table `mappe`
--

CREATE TABLE IF NOT EXISTS `mappe` (
  `ID_Mappe` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Clé de la table',
  `Longueur` int(11) NOT NULL COMMENT 'Longeur de la Mappe (nb de lignes du tableau)',
  `Largeur` int(11) NOT NULL COMMENT 'Largeur de la Mappe (nb de colonnes du tableau)',
  `ID_Entrepot` int(11) NOT NULL COMMENT 'Clé de l''entrepôt',
  PRIMARY KEY (`ID_Mappe`),
  UNIQUE KEY `ID_Mappe` (`ID_Mappe`),
  KEY `ID_Entrepot` (`ID_Entrepot`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Mappe décrivant un entrepôt';

-- --------------------------------------------------------

--
-- Structure de la table `robot`
--

CREATE TABLE IF NOT EXISTS `robot` (
  `ID_Robot` int(11) NOT NULL AUTO_INCREMENT ,
  `Nom_Robot` varchar(50) ,
  `Longueur_Robot` double ,
  `Largeur_Robot` double  ,
  `Vitesse_Robot` double  ,
  `Longueur_Capacite_De_Charge_Robot` double  ,
  `Largeur_Capactite_De_Charge_Robot` double  ,
  `Poids_Capacite_De_Charge_Robot` double  ,
  `ID_Equipe` int ,
  PRIMARY KEY (`ID_Robot`),
  UNIQUE KEY `ID_Robot` (`ID_Robot`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Robot';

-- --------------------------------------------------------

--
-- Structure de la table `simulation`
--

CREATE TABLE IF NOT EXISTS `simulation` (
  `ID_Simulation` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Clé de la table',
  `ID_Entrepot` int(11) NOT NULL COMMENT 'Clé de l''entrepôt',
  `ID_Equipe` int(11) NOT NULL COMMENT 'Clé de l''équipe',
  `ID_Liste_Taches` int(11) NOT NULL COMMENT 'Clé de l''équipe',
  PRIMARY KEY (`ID_Simulation`),
  UNIQUE KEY `ID_Simulation` (`ID_Simulation`),
  KEY `ID_Entrepot` (`ID_Entrepot`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Simulations sur un entrepôt';

-- --------------------------------------------------------

--
-- Structure de la table `tache`
--

CREATE TABLE IF NOT EXISTS `tache` (
  `ID_Tache` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Clé de la table',
  `Statut` int(11) NOT NULL COMMENT 'Statut de la tâche',
  `ID_Cargaison` int(11) NOT NULL COMMENT 'Clé de la cargaison',
  `ID_Armoire` int(11) NOT NULL COMMENT 'Clé de l''armoire',
  PRIMARY KEY (`ID_Tache`),
  UNIQUE KEY `ID_Tache` (`ID_Tache`),
  KEY `ID_Cargaison` (`ID_Cargaison`),
  KEY `ID_Armoire` (`ID_Armoire`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Tâche avec une cargaison et une armoire';

-- --------------------------------------------------------

--
-- Structure de la table `tile`
--

CREATE TABLE IF NOT EXISTS `tile` (
  `ID_Tile` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Clé de la table',
  `X` int(11) NOT NULL COMMENT 'Position en abcisse de la Tile sur la Mappe',
  `Y` int(11) NOT NULL COMMENT 'Position en ordonnée de la Tile sur la Mappe',
  `ID_Type` int(11) NOT NULL COMMENT 'Type de Tile (0=vide,1=Armoire,Id=Id objet)',
  `ID_Mappe` int(11) NOT NULL COMMENT 'Clé de la Mappe',
  PRIMARY KEY (`ID_Tile`),
  UNIQUE KEY `ID_Tile` (`ID_Tile`),
  KEY `ID_Mappe` (`ID_Mappe`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Tile de la Mappe';

-- --------------------------------------------------------

--
-- Structure de la table `equipe`
--

CREATE TABLE IF NOT EXISTS `equipe` (
  `ID_Equipe` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Clé de la table',
  `Nom_Equipe` varchar(100) COMMENT 'Nom d une équipe',
  PRIMARY KEY (`ID_Equipe`),
  UNIQUE KEY `ID_Equipe` (`ID_Equipe`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Une équipe';


--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `armoire`
--
ALTER TABLE `armoire`
  ADD CONSTRAINT `armoire_ibfk_1` FOREIGN KEY (`ID_Entrepot`) REFERENCES `entrepot` (`ID_Entrepot`);

--
-- Contraintes pour la table `cargaison`
--
ALTER TABLE `cargaison`
  ADD CONSTRAINT `cargaison_ibfk_1` FOREIGN KEY (`ID_Armoire`) REFERENCES `armoire` (`ID_Armoire`);
--
-- Contraintes pour la table `liste_taches`
--
/*ALTER TABLE `liste_taches`
  ADD CONSTRAINT `liste_taches_ibfk_1` FOREIGN KEY (`ID_Simulation`) REFERENCES `simulation` (`ID_Simulation`);*/
  
--
-- Contraintes pour la table `mappe`
--
ALTER TABLE `mappe`
  ADD CONSTRAINT `mappe_ibfk_1` FOREIGN KEY (`ID_Entrepot`) REFERENCES `entrepot` (`ID_Entrepot`);

--
-- Contraintes pour la table `simulation`
--
ALTER TABLE `simulation`
  ADD CONSTRAINT `simulation_ibfk_1` FOREIGN KEY (`ID_Entrepot`) REFERENCES `entrepot` (`ID_Entrepot`),
  ADD CONSTRAINT `simulation_ibfk_2` FOREIGN KEY (`ID_Equipe`) REFERENCES `equipe` (`ID_Equipe`),
  ADD CONSTRAINT `simulation_ibfk_3` FOREIGN KEY (`ID_Liste_Taches`) REFERENCES `liste_taches` (`ID_Liste_Taches`);

--
-- Contraintes pour la table `tache`
--
ALTER TABLE `tache`
  ADD CONSTRAINT `tache_ibfk_2` FOREIGN KEY (`ID_Armoire`) REFERENCES `armoire` (`ID_Armoire`),
  ADD CONSTRAINT `tache_ibfk_1` FOREIGN KEY (`ID_Cargaison`) REFERENCES `cargaison` (`ID_Cargaison`);

--
-- Contraintes pour la table `tile`
--
ALTER TABLE `tile`
  ADD CONSTRAINT `tile_ibfk_1` FOREIGN KEY (`ID_Mappe`) REFERENCES `mappe` (`ID_Mappe`);
  
--
-- Contraintes pour la table `robot`
--
ALTER TABLE `robot`
  ADD CONSTRAINT `robot_ibfk_1` FOREIGN KEY (`ID_Equipe`) REFERENCES `equipe` (`ID_Equipe`);
  

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
