SELECT 
    FARMACIA.nome
FROM
    FARMACIA,
    MORADA
WHERE
    MORADA.Localidade = 'Braga';


SELECT DISTINCT
    CLIENTE.*
FROM
    CLIENTE
        JOIN
    PRESCRICAO ON CLIENTE.IdCliente = PRESCRICAO.IdCliente
WHERE
    PRESCRICAO.DataValidade < CURRENT_DATE();
    
    
SELECT 
    m.nome
FROM
    MEDICAMENTO AS m
        INNER JOIN
    ENCOMENDA AS e ON e.IdMedicamento = m.IdMedicamento
WHERE
    m.Unidades_Disp < m.stock
        AND m.IdMedicamento NOT IN (SELECT 
            IdMedicamento
        FROM
            ENCOMENDA
        WHERE
            DataEncomenda > CURRENT_DATE - 7);
		
