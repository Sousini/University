def salvarhtml(minidade,maxidade,numgeneros,modalidades,modalidadesporano,aptosporano,nomestrocados,total):
    html_content = f"""<!DOCTYPE html>
    <html lang="pt-BR">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Relatório de Dados Moderno</title>
        <style>
            @import url('https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;600;700&display=swap');
            body {{
                font-family: 'Poppins', sans-serif;
                background-color: #f5f7fa;
                margin: 0;
                padding: 20px;
                color: #333;
                line-height: 1.6;
            }}
            h1, h2 {{
                color: #333;
                font-weight: 700;
                text-align: center;
                margin-bottom: 20px;
            }}
            h1 {{
                font-size: 2.5rem;
            }}
            h2 {{
                font-size: 1.8rem;
            }}
            .card {{
                background: #fff;
                border-radius: 16px;
                padding: 30px;
                margin: 30px auto;
                max-width: 900px;
                box-shadow: 0 6px 12px rgba(0, 0, 0, 0.08);
                transition: all 0.3s ease;
            }}
            .card:hover {{
                transform: translateY(-5px);
                box-shadow: 0 8px 15px rgba(0, 0, 0, 0.15);
            }}
            .info-box {{
                display: flex;
                flex-wrap: wrap;
                justify-content: center;
                gap: 20px;
            }}
            .info-box div {{
                background: linear-gradient(135deg, #83eaf1, #63a4ff);
                color: white;
                padding: 25px 30px;
                border-radius: 12px;
                box-shadow: 0 4px 10px rgba(0, 0, 0, 0.15);
                font-weight: bold;
                font-size: 1.2rem;
                flex: 1 1 120px;
                text-align: center;
            }}
            table {{
                width: 100%;
                border-collapse: collapse;
                margin-bottom: 30px;
                font-size: 1rem;
            }}
            th, td {{
                padding: 20px;
                text-align: center;
            }}
            th {{
                background-color: #2d9cdb;
                color: white;
                font-weight: 600;
            }}
            td {{
                background-color: #f3f7fb;
                border-bottom: 1px solid #ddd;
            }}
            .json-container {{
                background-color: #f9f9f9;
                border: 1px solid #ddd;
                padding: 15px;
                white-space: normal;  /* Allows wrapping across multiple lines */
                word-wrap: break-word;  /* Ensures long sequences are wrapped */
                border-radius: 12px;
                box-shadow: 0 3px 8px rgba(0, 0, 0, 0.1);
                font-family: 'Courier New', monospace;  /* Use a monospace font for better readability */
                line-height: 1.4;  /* Add some spacing between lines */
            }}
            .dropdown {{
                display: flex;
                justify-content: center;
                align-items: center;
                margin-bottom: 20px;
            }}
            .dropdown label {{
                margin-right: 10px;
                font-size: 1.1rem;
                color: #333;
            }}
            select {{
                padding: 10px 20px;
                font-size: 1rem;
                border: 2px solid #ccc;
                border-radius: 10px;
                background: white;
                transition: border 0.3s;
            }}
            select:focus {{
                border-color: #2d9cdb;
                outline: none;
            }}
            button {{
                padding: 12px 30px;
                background-color: #66d2e4;
                color: white;
                border: none;
                border-radius: 8px;
                font-size: 1rem;
                cursor: pointer;
                box-shadow: 0 4px 10px rgba(0, 0, 0, 0.2);
                transition: background-color 0.3s, transform 0.3s;
            }}
            button:hover {{
                background-color: #2d9cdb;
                transform: translateY(-3px);
            }}
            tr:hover {{
                background-color: #e8f4fa;
            }}
            @media (max-width: 768px) {{
                .card {{
                    padding: 20px;
                    margin: 20px;
                }}
                h1 {{
                    font-size: 2rem;
                }}
                h2 {{
                    font-size: 1.5rem;
                }}
                .info-box div {{
                    padding: 20px;
                    font-size: 1rem;
                }}
                select {{
                    width: 100%;
                    margin-top: 10px;
                }}
            }}
        </style>
    </head>
    <body>

        <h1>Relatório Insano</h1>

        <section class="card">
            <h2>Idades Extremas</h2>
            <div class="info-box">
                <div>Idade Mínima<br><strong>{minidade}</strong></div>
                <div>Idade Máxima<br><strong>{maxidade}</strong></div>
            </div>
        </section>

        <section class="card">
            <h2>Distribuição por Género</h2>
            <div class="info-box">
                <div>Masculino<br><strong>{numgeneros['M']}</strong></div>
                <div>Feminino<br><strong>{numgeneros['F']}</strong></div>
                <div>Percentagem Masculino<br><strong>{(numgeneros['M'] / total) * 100:.2f}%</strong></div>
                <div>Percentagem Feminino<br><strong>{(numgeneros['F'] / total) * 100:.2f}%</strong></div>
            </div>
        </section>

        <section class="card">
            <h2>Distribuição por Modalidade em Cada Ano</h2>
            <div class="dropdown">
                <label for="year-select">Selecione o Ano:</label>
                <select id="year-select" onchange="updateTable()">
                    {"".join(f'<option value="{ano}">{ano}</option>' for ano in sorted(modalidadesporano.keys()))}
                </select>
            </div>
            <div class="info-box" id="modalidades-info">
                <!-- Modalities info will be populated here -->
            </div>
        </section>

        <section class="card">
            <h2>Aptos e Não Aptos por Ano</h2>
            <div class="info-box">
                {"".join(f"<div>Ano: {ano}<br>Aptos: <strong>{aptosporano[ano]['aptos']}</strong><br>Não Aptos: <strong>{aptosporano[ano]['nao_aptos']}</strong></div>" for ano in sorted(aptosporano.keys()))}
            </div>
        </section>

        <section class="card">
            <h2>Nomes Trocados (Formato JSON)</h2>
            <div class="json-container">
                <div>{nomestrocados}</div>  <!-- Replace <pre> with <div> -->
            </div>
        </section>

        <script>
            const modalidadesporano = {modalidadesporano};
            const modalidadesInfo = document.getElementById('modalidades-info');
            
            function updateTable() {{
                const year = document.getElementById('year-select').value;
                const modalidades = modalidadesporano[year];
                modalidadesInfo.innerHTML = ''; 

                for (const [modalidade, quantidade] of Object.entries(modalidades)) {{
                    const infoDiv = `<div>${{modalidade}}<br><strong>${{quantidade}}</strong></div>`;
                    modalidadesInfo.innerHTML += infoDiv;
                }}
            }}
            window.onload = updateTable;
        </script>
    </body>
    </html>
    """

    # Salvar o conteúdo HTML em um arquivo
    with open('relatorio.html', 'w', encoding='utf-8') as output_file:
        output_file.write(html_content)
    
    return 200