INSERT INTO MORADA (Rua, Porta, Localidade, CodPostal) VALUES 
('Rua das Flores', 12, 'Lisboa', '1000-001'),
('Avenida dos Aliados', 45, 'Porto', '4000-067'),
('Praça da Liberdade', 23, 'Braga', '4700-229'),
('Rua da Alegria', 89, 'Faro', '8000-303');

INSERT INTO FARMACIA (Nome, DataInicio, IdMorada_1) VALUES 
('Farmácia Central', '2010-05-10', 1),
('Farmácia Aliados', '2015-08-20', 2);

INSERT INTO FORNECEDOR (IdFornecedor, Nome, Estado, IdMorada) VALUES 
(1, 'Fornecedor A', 1, 3),
(2, 'Fornecedor B', 1, 4);

INSERT INTO CLIENTE (IdCliente, Nome, DataNascimento, Morada) VALUES 
(1, 'João Silva', '1985-07-12', 1),
(2, 'Maria Oliveira', '1992-11-05', 2);

INSERT INTO PRESCRICAO (Numero, DataPrescricao, Estado, IdCliente, DataValidade) VALUES 
(1001, '2023-09-15', 1, 1, '2024-09-15'),
(1002, '2023-10-20', 1, 2, '2024-10-20');

INSERT INTO TIPO (Designacao) VALUES 
('Farmacêutico'),
('Assistente');

INSERT INTO FUNCIONARIO (NMecanografico, Nome, DataNascimento, IdFarmacia, Tipo, Morada) VALUES 
(101, 'Pedro Costa', '1980-04-12', 1, 1, 3),
(102, 'Ana Santos', '1990-01-25', 2, 2, 4);

INSERT INTO MEDICAMENTO (IdMedicamento, Nome, Unidades_Disp, Stock, Preco, DataValidade, Dosagem, Prescricao, Estado, IdFarmacia) VALUES 
(1001, 'Paracetamol', 20, 100, 25.2,'2025-12-30', 500, 1001, 1, 1),
(1002, 'Ibuprofeno', 30, 50, 5.4,'2024-06-10', 200, 1002, 1, 2),
(1003, 'Medicamento 3', 120, 60, 15.3, '2024-07-12', 300, 1001, 1, 1);

INSERT INTO POSOLOGIA (Frequencia, Duracao, Notas) VALUES 
('1 vez ao dia', 7, 'Tomar após o almoço'),
('2 vezes ao dia', 10, 'Tomar de manhã e à noite');

INSERT INTO POSOLOGIA_PRODUTO (IdMedicamento, IdPosologia) VALUES 
(1001, 1),
(1002, 2);
INSERT INTO ENCOMENDA (NEncomenda, Estado, Valor, Unidades, DataEncomenda, DataEntrega, IdFornecedor, IdMedicamento) VALUES 
(5001, 1, '500.00', 100, '2023-07-01', '2023-07-05', 1, 1001),
(5002, 2, '300.00', 50, '2023-08-15', '2023-08-18', 2, 1002);
