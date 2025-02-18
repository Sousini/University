def salvarhtml(processosporano, nomesproprios, apelidos, recsportio, pais):
    html_content = f"""<!DOCTYPE html>
    <html lang="pt-BR">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Relatório de Processos nos Róis de Confessados</title>
        <style>
            body {{
                font-family: Arial, sans-serif;
                background-color: #f5f5f5;
                margin: 0;
                padding: 20px;
                color: #333;
            }}
            h1, h2 {{
                text-align: center;
                color: #333;
            }}
            .section {{
                background-color: #fff;
                border-radius: 10px;
                padding: 20px;
                margin: 20px auto;
                max-width: 800px;
                box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            }}
            .table {{
                width: 100%;
                border-collapse: collapse;
                margin: 20px 0;
            }}
            .table th, .table td {{
                padding: 12px;
                text-align: left;
                border-bottom: 1px solid #ddd;
            }}
            .table th {{
                background-color: #4CAF50;
                color: white;
            }}
            .json-container {{
                background-color: #e8e8e8;
                padding: 10px;
                border-radius: 5px;
                font-family: monospace;
                white-space: pre-wrap;
            }}
        </style>
    </head>
    <body>
        <h1>Relatório de Processos nos Róis de Confessados</h1>

        <div class="section">
            <h2>Frequência de Processos por Ano</h2>
            <table class="table">
                <tr><th>Ano</th><th>Número de Processos</th></tr>
                {"".join(f"<tr><td>{ano}</td><td>{len(ids)}</td></tr>" for ano, ids in sorted(processosporano.items()))}
            </table>
        </div>

        <div class="section">
            <h2>Nomes Próprios Mais Frequentes</h2>
            <table class="table">
                <tr><th>Nome</th><th>Frequência</th></tr>
                {"".join(f"<tr><td>{nome}</td><td>{freq}</td></tr>" for nome, freq in sorted(nomesproprios.items(), key=lambda item: item[1], reverse=True))}
            </table>
        </div>

        <div class="section">
            <h2>Apelidos Mais Frequentes</h2>
            <table class="table">
                <tr><th>Apelido</th><th>Frequência</th></tr>
                {"".join(f"<tr><td>{apelido}</td><td>{freq}</td></tr>" for apelido, freq in sorted(apelidos.items(), key=lambda item: item[1], reverse=True))}
            </table>
        </div>

        <div class="section">
            <h2>Processos com Recomendações de Tios</h2>
            <p>Total de processos recomendados por tios: <strong>{recsportio}</strong></p>
        </div>

        <div class="section">
            <h2>Pais com Mais de Um Filho Confessado</h2>
            <table class="table">
                <tr><th>Pai</th><th>Filhos Confessados</th></tr>
                {"".join(f"<tr><td>{pai}</td><td>{len(filhos)}</td></tr>" for pai, filhos in pais.items() if len(filhos) > 1)}
            </table>
        </div>
    </body>
    </html>
    """
    
    with open('index.html', 'w', encoding='utf-8') as file:
        file.write(html_content)
    
    return 200
