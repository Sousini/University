

CREATE DATABASE IF NOT EXISTS Farmacia;

USE Farmacia;

CREATE TABLE IF NOT EXISTS MORADA (
	IdMorada INT NOT NULL AUTO_INCREMENT,
    Rua VARCHAR(45),
    Porta INT,
    Localidade VARCHAR(45),
    CodPostal VARCHAR(45),
    PRIMARY KEY (IdMorada)
);


CREATE TABLE IF NOT EXISTS FARMACIA(
	IdFarmacia INT NOT NULL AUTO_INCREMENT,
    Nome VARCHAR(45),
    DataInicio DATE,
    idMorada_1 INT,
    PRIMARY KEY (IdFarmacia),
    FOREIGN KEY (IdMorada_1) references MORADA(IdMorada)
);

CREATE TABLE IF NOT EXISTS FORNECEDOR(
	IdFornecedor INT NOT NULL,
    Nome VARCHAR(45) NOT NULL,
    Estado TINYINT NOT NULL,
    IdMorada INT,
    PRIMARY KEY (IdFornecedor),
    FOREIGN KEY (IdMorada) references MORADA(IdMorada)
);

CREATE TABLE IF NOT EXISTS CLIENTE(
	IdCliente INT NOT NULL,
    Nome VARCHAR(45) NOT NULL,
    DataNascimento DATETIME,
    Morada INT,
    PRIMARY KEY (IdCLiente),
    FOREIGN KEY (Morada) references MORADA(idMorada)
);

CREATE TABLE IF NOT EXISTS PRESCRICAO(
	Numero INT NOT NULL,
    DataPrescricao DATE,
    Estado TINYINT,
    IdCLiente INT,
    DataValidade DATE,
    PRIMARY KEY (Numero),
    FOREIGN KEY (IdCliente) references CLIENTE(IdCliente)
);

CREATE TABLE IF NOT EXISTS TIPO(
	IdTipo INT NOT NULL AUTO_INCREMENT,
    Designacao VARCHAR(45),
    PRIMARY KEY(IdTipo)
);

DESC TIPO;

ALTER TABLE TIPO MODIFY COLUMN DESIGNACAO VARCHAR(500);

CREATE TABLE IF NOT EXISTS FUNCIONARIO(
	NMecanografico INT NOT NULL,
    Nome VARCHAR(45),
    DataNascimento DATE,
    IdFarmacia INT,
    Tipo INT,
    Morada INT,
    PRIMARY KEY (NMecanografico),
    FOREIGN KEY (IdFarmacia) references FARMACIA(IdFarmacia),
    FOREIGN KEY (Tipo) references TIPO(IdTipo),
    FOREIGN KEY (Morada) references MORADA(IdMorada)
);

CREATE TABLE IF NOT EXISTS MEDICAMENTO(
	IdMedicamento INT NOT NULL,
    Nome VARCHAR(45),
    Unidades_Disp INT NOT NULL,
    Stock INT NOT NULL,
    Preco FLOAT,
    DataValidade DATE,
    Dosagem INT,
    Prescricao INT,
    Estado TINYINT,
    IdFarmacia INT,
    PRIMARY KEY (IdMedicamento),
    FOREIGN KEY (Prescricao) references PRESCRICAO(Numero),
    FOREIGN KEY (IdFarmAcia) references FARMACIA(IdFarmacia)
);

CREATE TABLE IF NOT EXISTS POSOLOGIA(
	Identificador INT NOT NULL AUTO_INCREMENT,
    Frequencia VARCHAR(45) NOT NULL,
    Duracao INT NOT NULL,
    Notas VARCHAR(500),
    PRIMARY KEY (Identificador)
);

CREATE TABLE IF NOT EXISTS POSOLOGIA_PRODUTO(
	IdMedicamento INT,
    IdPosologia INT,
    PRIMARY KEY(IdMedicamento, IdPosologia),
    FOREIGN KEY (IdMedicamento) references MEDICAMENTO(IdMedicamento),
    FOREIGN KEY (IdPosologia) references POSOLOGIA(Identificador)
);

CREATE TABLE IF NOT EXISTS ENCOMENDA(
	NEncomenda INT NOT NULL,
    Estado TINYINT,
    Valor VARCHAR(45),
    Unidades INT,
    DataEncomenda DATE,
    DataEntrega DATE,
    IdFornecedor INT,
    IdMedicamento INT,
    PRIMARY KEY(NEncomenda),
    FOREIGN KEY (IdFornecedor) references FORNECEDOR(IdFornecedor),
    FOREIGN KEY (IdMedicamento) references MEDICAMENTO(IdMedicamento)
);

