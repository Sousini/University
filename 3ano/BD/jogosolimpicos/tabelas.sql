-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema JogosOlimpicos
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `JogosOlimpicos` ;

-- -----------------------------------------------------
-- Schema JogosOlimpicos
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `JogosOlimpicos` ;
USE `JogosOlimpicos` ;

-- -----------------------------------------------------
-- Table `JogosOlimpicos`.`Jogos_Olimpicos`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `JogosOlimpicos`.`Jogos_Olimpicos` ;

CREATE TABLE IF NOT EXISTS `JogosOlimpicos`.`Jogos_Olimpicos` (
  `Identificador` INT NOT NULL AUTO_INCREMENT,
  `Ano` VARCHAR(4) NOT NULL,
  `Pais_Organizador` VARCHAR(64) NOT NULL,
  `Contacto` VARCHAR(64) NOT NULL,
  `Data_Inicio` DATE NOT NULL,
  `Data_Fim` DATE NOT NULL,
  PRIMARY KEY (`Identificador`),
  UNIQUE INDEX `Identificador_UNIQUE` (`Identificador` ASC) VISIBLE,
  UNIQUE INDEX `Ano_UNIQUE` (`Ano` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `JogosOlimpicos`.`Pais`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `JogosOlimpicos`.`Pais` ;

CREATE TABLE IF NOT EXISTS `JogosOlimpicos`.`Pais` (
  `Identificador` INT NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(64) NOT NULL,
  `Contacto` VARCHAR(64) NOT NULL,
  PRIMARY KEY (`Identificador`),
  UNIQUE INDEX `Identificador_UNIQUE` (`Identificador` ASC) VISIBLE,
  UNIQUE INDEX `Nome_UNIQUE` (`Nome` ASC) VISIBLE,
  UNIQUE INDEX `Contacto_UNIQUE` (`Contacto` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `JogosOlimpicos`.`Participação`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `JogosOlimpicos`.`Participação` ;

CREATE TABLE IF NOT EXISTS `JogosOlimpicos`.`Participação` (
  `Identificador_JogosOlimpicos` INT NOT NULL,
  `Identificador_Pais` INT NOT NULL,
  INDEX `fk_JogosOlimpicos_idx` (`Identificador_JogosOlimpicos` ASC) VISIBLE,
  INDEX `fk_Pais_idx` (`Identificador_Pais` ASC) VISIBLE,
  PRIMARY KEY (`Identificador_JogosOlimpicos`, `Identificador_Pais`),
  CONSTRAINT `fk_JogosOlimpicos`
    FOREIGN KEY (`Identificador_JogosOlimpicos`)
    REFERENCES `JogosOlimpicos`.`Jogos_Olimpicos` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Pais`
    FOREIGN KEY (`Identificador_Pais`)
    REFERENCES `JogosOlimpicos`.`Pais` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `JogosOlimpicos`.`Modalidade`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `JogosOlimpicos`.`Modalidade` ;

CREATE TABLE IF NOT EXISTS `JogosOlimpicos`.`Modalidade` (
  `Identificador` INT NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(32) NOT NULL,
  PRIMARY KEY (`Identificador`),
  UNIQUE INDEX `Identificador_UNIQUE` (`Identificador` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `JogosOlimpicos`.`Categoria`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `JogosOlimpicos`.`Categoria` ;

CREATE TABLE IF NOT EXISTS `JogosOlimpicos`.`Categoria` (
  `Identificador` INT NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(32) NOT NULL,
  `Genero` VARCHAR(16) NOT NULL,
  `Peso` FLOAT NULL,
  `Duração` TIME NULL,
  `Distância` FLOAT NULL,
  `Identificador_Modalidade` INT NOT NULL,
  PRIMARY KEY (`Identificador`),
  UNIQUE INDEX `Identificador_UNIQUE` (`Identificador` ASC) VISIBLE,
  INDEX `fk_Modalidade_idx` (`Identificador_Modalidade` ASC) VISIBLE,
  CONSTRAINT `fk_Modalidade`
    FOREIGN KEY (`Identificador_Modalidade`)
    REFERENCES `JogosOlimpicos`.`Modalidade` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `JogosOlimpicos`.`Equipa`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `JogosOlimpicos`.`Equipa` ;

CREATE TABLE IF NOT EXISTS `JogosOlimpicos`.`Equipa` (
  `Identificador` INT NOT NULL AUTO_INCREMENT,
  `Identificador_Pais` INT NOT NULL,
  `Identificador_Categoria` INT NOT NULL,
  PRIMARY KEY (`Identificador`),
  UNIQUE INDEX `Identificador_UNIQUE` (`Identificador` ASC) VISIBLE,
  INDEX `fk_Pais_idx` (`Identificador_Pais` ASC) VISIBLE,
  INDEX `fk_Categoria_idx` (`Identificador_Categoria` ASC) VISIBLE,
  CONSTRAINT `fk_Equipa_Pais`
    FOREIGN KEY (`Identificador_Pais`)
    REFERENCES `JogosOlimpicos`.`Pais` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Equipa_Categoria`
    FOREIGN KEY (`Identificador_Categoria`)
    REFERENCES `JogosOlimpicos`.`Categoria` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `JogosOlimpicos`.`Atleta`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `JogosOlimpicos`.`Atleta` ;

CREATE TABLE IF NOT EXISTS `JogosOlimpicos`.`Atleta` (
  `Identificador` INT NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(128) NOT NULL,
  `Data_Nascimento` DATE NOT NULL,
  `Género` VARCHAR(16) NOT NULL,
  `Peso` FLOAT NOT NULL,
  `Altura` FLOAT NOT NULL,
  PRIMARY KEY (`Identificador`),
  UNIQUE INDEX `Identificador_UNIQUE` (`Identificador` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `JogosOlimpicos`.`Equipa_Atleta`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `JogosOlimpicos`.`Equipa_Atleta` ;

CREATE TABLE IF NOT EXISTS `JogosOlimpicos`.`Equipa_Atleta` (
  `Identificador_Equipa` INT NOT NULL,
  `Identificador_Atleta` INT NOT NULL,
  INDEX `fk_Equipa_idx` (`Identificador_Equipa` ASC) VISIBLE,
  INDEX `fk_Atleta_idx` (`Identificador_Atleta` ASC) VISIBLE,
  PRIMARY KEY (`Identificador_Equipa`, `Identificador_Atleta`),
  CONSTRAINT `fk_Equipa`
    FOREIGN KEY (`Identificador_Equipa`)
    REFERENCES `JogosOlimpicos`.`Equipa` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Atleta`
    FOREIGN KEY (`Identificador_Atleta`)
    REFERENCES `JogosOlimpicos`.`Atleta` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `JogosOlimpicos`.`Endereço`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `JogosOlimpicos`.`Endereço` ;

CREATE TABLE IF NOT EXISTS `JogosOlimpicos`.`Endereço` (
  `Identificador` INT NOT NULL AUTO_INCREMENT,
  `Morada` VARCHAR(64) NOT NULL,
  `Localidade` VARCHAR(32) NOT NULL,
  PRIMARY KEY (`Identificador`),
  UNIQUE INDEX `Identificador_UNIQUE` (`Identificador` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `JogosOlimpicos`.`Resultados`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `JogosOlimpicos`.`Resultados` ;

CREATE TABLE IF NOT EXISTS `JogosOlimpicos`.`Resultados` (
  `Identificador` INT NOT NULL AUTO_INCREMENT,
  `Identificador_Equipa1` INT NOT NULL,
  `Identificador_Equipa2` INT NOT NULL,
  `Identificador_Equipa3` INT NOT NULL,
  `Identificador_Prova` INT NOT NULL,
  PRIMARY KEY (`Identificador`),
  UNIQUE INDEX `Identificador_UNIQUE` (`Identificador` ASC) VISIBLE,
  INDEX `fk_Equipa1_idx` (`Identificador_Equipa1` ASC) VISIBLE,
  INDEX `fk_Equipa2_idx` (`Identificador_Equipa2` ASC) VISIBLE,
  INDEX `fk_Equipa3_idx` (`Identificador_Equipa3` ASC) VISIBLE,
  INDEX `fk_Prova_idx` (`Identificador_Prova` ASC) VISIBLE,
  CONSTRAINT `fk_Equipa1`
    FOREIGN KEY (`Identificador_Equipa1`)
    REFERENCES `JogosOlimpicos`.`Equipa` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Equipa2`
    FOREIGN KEY (`Identificador_Equipa2`)
    REFERENCES `JogosOlimpicos`.`Equipa` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Equipa3`
    FOREIGN KEY (`Identificador_Equipa3`)
    REFERENCES `JogosOlimpicos`.`Equipa` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Prova`
    FOREIGN KEY (`Identificador_Prova`)
    REFERENCES `JogosOlimpicos`.`Prova` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `JogosOlimpicos`.`Prova`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `JogosOlimpicos`.`Prova` ;

CREATE TABLE IF NOT EXISTS `JogosOlimpicos`.`Prova` (
  `Identificador` INT NOT NULL AUTO_INCREMENT,
  `Data` DATE NOT NULL,
  `Fase` VARCHAR(32) NOT NULL,
  `Identificador_Categoria` INT NOT NULL,
  `Identificador_Endereço` INT NOT NULL,
  `Identificador_Resultado` INT NOT NULL,
  PRIMARY KEY (`Identificador`),
  UNIQUE INDEX `Identificador_UNIQUE` (`Identificador` ASC) VISIBLE,
  INDEX `fk_Categoria_idx` (`Identificador_Categoria` ASC) VISIBLE,
  INDEX `fk_Endereço_idx` (`Identificador_Endereço` ASC) VISIBLE,
  INDEX `fk_Resultado_idx` (`Identificador_Resultado` ASC) VISIBLE,
  CONSTRAINT `fk_Categoria`
    FOREIGN KEY (`Identificador_Categoria`)
    REFERENCES `JogosOlimpicos`.`Categoria` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Endereço`
    FOREIGN KEY (`Identificador_Endereço`)
    REFERENCES `JogosOlimpicos`.`Endereço` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Resultado`
    FOREIGN KEY (`Identificador_Resultado`)
    REFERENCES `JogosOlimpicos`.`Resultados` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `JogosOlimpicos`.`Equipa_Prova`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `JogosOlimpicos`.`Equipa_Prova` ;

CREATE TABLE IF NOT EXISTS `JogosOlimpicos`.`Equipa_Prova` (
  `Identificador_Equipa` INT NOT NULL,
  `Identificador_Prova` INT NOT NULL,
  INDEX `fk_Equipa_idx` (`Identificador_Equipa` ASC) VISIBLE,
  INDEX `fk_Prova_idx` (`Identificador_Prova` ASC) VISIBLE,
  CONSTRAINT `fk_EquipaP_Equipa`
    FOREIGN KEY (`Identificador_Equipa`)
    REFERENCES `JogosOlimpicos`.`Equipa` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_EquipaP_Prova`
    FOREIGN KEY (`Identificador_Prova`)
    REFERENCES `JogosOlimpicos`.`Prova` (`Identificador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
