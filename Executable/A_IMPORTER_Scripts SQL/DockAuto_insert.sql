-- phpMyAdmin SQL Dump
-- version 4.0.4
-- http://www.phpmyadmin.net
--
-- Client: localhost
-- Généré le: Dim 13 Juillet 2014 à 17:38
-- Version du serveur: 5.6.12-log
-- Version de PHP: 5.4.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données: `dockautodb`
--
CREATE DATABASE IF NOT EXISTS `dockautodb` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `dockautodb`;

--
-- Contenu de la table `entrepot`
--

INSERT INTO `entrepot` (`ID_Entrepot`, `Nom_Entrepot`, `Longueur_Entrepot`, `Largeur_Entrepot`) VALUES
(1, 'simple', 10, 10),
(2, 'depot 2', 4, 14),
(3, 'Depot 3 - Carre', 24, 24),
(4, 'depot 4 - barrage', 9, 14);

--
-- Contenu de la table `equipe`
--

INSERT INTO `equipe` (`ID_Equipe`, `Nom_Equipe`) VALUES
(1, 'Equipe1'),
(2, 'Equipe 2 - un seul robot'),
(3, 'Equipe 3 - 2 robots');

--
-- Contenu de la table `liste_taches`
--

INSERT INTO `liste_taches` (`ID_Liste_Taches`, `Nom_Liste_Taches`) VALUES
(1, 'Taches1'),
(2, 'liste tache 2'),
(3, 'liste tache carre'),
(4, 'liste barage');

--
-- Contenu de la table `robot`
--

INSERT INTO `robot` (`ID_Robot`, `Nom_Robot`, `Longueur_Robot`, `Largeur_Robot`, `Vitesse_Robot`, `Longueur_Capacite_De_Charge_Robot`, `Largeur_Capactite_De_Charge_Robot`, `Poids_Capacite_De_Charge_Robot`, `ID_Equipe`) VALUES
(1, 'Robot1', 1, 1, 1, 1, 1, 1, 1),
(2, 'Robot2', 1, 1, 1, 1, 1, 1, 1),
(3, 'robot 1', 10, 10, 10, 10, 10, 10, 2),
(4, 'robot 1', 10, 10, 10, 10, 10, 10, 3),
(5, 'robot 2', 10, 10, 10, 10, 10, 10, 3);

--
-- Contenu de la table `simulation`
--

INSERT INTO `simulation` (`ID_Simulation`, `Nom_Simulation`, `ID_Entrepot`, `ID_Equipe`, `ID_Liste_Taches`) VALUES
(1, 'Simulation1 - basique', 1, 1, 1),
(2, 'simulation 2 - Serpentin', 2, 2, 2),
(3, 'Simulation 3 - Carre', 3, 3, 3),
(4, 'simulation 4 - barrage', 4, 2, 4);

--
-- Contenu de la table `tache`
--

INSERT INTO `tache` (`ID_Tache`, `Poids_Tache`, `Depart_X`, `Depart_Y`, `Arrive_X`, `Arrive_Y`, `ID_Liste_Taches`, `ID_Robot`) VALUES
(1, 1, 2, 1, 0, 1, 1, 1),
(2, 1, 9, 1, 7, 1, 1, 2),
(3, 20, 3, 12, 2, 1, 2, 3),
(4, 40, 2, 1, 3, 12, 2, 3),
(5, 20, 10, 11, 14, 11, 3, 4),
(6, 20, 22, 2, 2, 3, 3, 5),
(7, 30, 4, 11, 8, 1, 4, 3);

--
-- Contenu de la table `tile`
--

INSERT INTO `tile` (`ID_Tile`, `X`, `Y`, `ID_Type`, `ID_Entrepot`) VALUES
(1, 0, 1, -3, 1),
(2, 1, 8, -5, 1),
(3, 2, 1, -3, 1),
(4, 7, 1, -3, 1),
(5, 8, 9, -5, 1),
(6, 9, 1, -3, 1),
(7, 0, 8, -3, 2),
(8, 0, 12, -3, 2),
(9, 1, 6, -3, 2),
(10, 1, 8, -3, 2),
(11, 1, 10, -3, 2),
(12, 1, 12, -3, 2),
(13, 2, 1, -3, 2),
(14, 2, 6, -3, 2),
(15, 2, 8, -3, 2),
(16, 2, 10, -3, 2),
(17, 2, 12, -3, 2),
(18, 3, 6, -3, 2),
(19, 3, 8, -3, 2),
(20, 3, 10, -3, 2),
(21, 3, 12, -3, 2),
(22, 4, 6, -3, 2),
(23, 4, 10, -3, 2),
(24, 4, 14, -5, 2),
(25, 2, 3, -3, 3),
(26, 5, 5, -3, 3),
(27, 5, 6, -3, 3),
(28, 5, 7, -3, 3),
(29, 5, 8, -3, 3),
(30, 5, 9, -3, 3),
(31, 5, 10, -3, 3),
(32, 5, 11, -3, 3),
(33, 5, 12, -3, 3),
(34, 5, 13, -3, 3),
(35, 5, 14, -3, 3),
(36, 5, 15, -3, 3),
(37, 5, 23, -5, 3),
(38, 6, 5, -3, 3),
(39, 6, 15, -3, 3),
(40, 7, 5, -3, 3),
(41, 7, 15, -3, 3),
(42, 8, 5, -3, 3),
(43, 8, 9, -3, 3),
(44, 8, 10, -3, 3),
(45, 8, 11, -3, 3),
(46, 8, 12, -3, 3),
(47, 8, 13, -3, 3),
(48, 8, 15, -3, 3),
(49, 9, 5, -3, 3),
(50, 9, 13, -3, 3),
(51, 9, 15, -3, 3),
(52, 10, 5, -3, 3),
(53, 10, 11, -3, 3),
(54, 10, 13, -3, 3),
(55, 10, 15, -3, 3),
(56, 11, 5, -3, 3),
(57, 11, 13, -3, 3),
(58, 12, 5, -3, 3),
(59, 12, 13, -3, 3),
(60, 13, 5, -3, 3),
(61, 13, 13, -3, 3),
(62, 14, 5, -3, 3),
(63, 14, 11, -3, 3),
(64, 14, 13, -3, 3),
(65, 15, 5, -3, 3),
(66, 15, 13, -3, 3),
(67, 15, 15, -3, 3),
(68, 16, 5, -3, 3),
(69, 16, 13, -3, 3),
(70, 16, 15, -3, 3),
(71, 17, 5, -3, 3),
(72, 17, 9, -3, 3),
(73, 17, 10, -3, 3),
(74, 17, 11, -3, 3),
(75, 17, 12, -3, 3),
(76, 17, 13, -3, 3),
(77, 17, 15, -3, 3),
(78, 18, 5, -3, 3),
(79, 18, 15, -3, 3),
(80, 19, 5, -3, 3),
(81, 19, 15, -3, 3),
(82, 20, 5, -3, 3),
(83, 20, 15, -3, 3),
(84, 20, 23, -5, 3),
(85, 21, 5, -3, 3),
(86, 21, 6, -3, 3),
(87, 21, 7, -3, 3),
(88, 21, 8, -3, 3),
(89, 21, 9, -3, 3),
(90, 21, 10, -3, 3),
(91, 21, 11, -3, 3),
(92, 21, 12, -3, 3),
(93, 21, 13, -3, 3),
(94, 21, 14, -3, 3),
(95, 21, 15, -3, 3),
(96, 22, 2, -3, 3),
(97, 0, 4, -3, 4),
(98, 1, 4, -3, 4),
(99, 1, 8, -3, 4),
(100, 2, 4, -3, 4),
(101, 2, 8, -3, 4),
(102, 3, 4, -3, 4),
(103, 3, 8, -3, 4),
(104, 4, 8, -3, 4),
(105, 4, 11, -3, 4),
(106, 4, 13, -5, 4),
(107, 5, 4, -3, 4),
(108, 5, 8, -3, 4),
(109, 6, 4, -3, 4),
(110, 6, 8, -3, 4),
(111, 7, 4, -3, 4),
(112, 7, 8, -3, 4),
(113, 8, 1, -3, 4),
(114, 8, 4, -3, 4),
(115, 8, 8, -3, 4),
(116, 9, 4, -3, 4);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
