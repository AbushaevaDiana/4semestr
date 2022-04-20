/*Добавить внешние ключи.*/
ALTER TABLE [production]
  ADD CONSTRAINT FK_production_company
  FOREIGN KEY (id_company) REFERENCES [company] (id_company)
ALTER TABLE [production]
  ADD CONSTRAINT FK_production_medicine
  FOREIGN KEY (id_medicine) REFERENCES [medicine] (id_medicine)
ALTER TABLE [order]
  ADD CONSTRAINT FK_order_production
  FOREIGN KEY (id_production) REFERENCES [production] (id_production)
ALTER TABLE [order]
  ADD CONSTRAINT FK_order_dealer
  FOREIGN KEY (id_dealer) REFERENCES [dealer] (id_dealer)
ALTER TABLE [order]
  ADD CONSTRAINT FK_order_pharmacy
  FOREIGN KEY (id_pharmacy) REFERENCES [pharmacy] (id_pharmacy)
ALTER TABLE [dealer]
  ADD CONSTRAINT FK_dealer_company
  FOREIGN KEY (id_company) REFERENCES [company] (id_company)

/*Выдать информацию по всем заказам лекарства “Кордерон” компании “Аргус” с
указанием названий аптек, дат, объема заказов*/
SELECT medicine.name, [order].date, [order].quantity, pharmacy.name AS pharmacy_name FROM [order]
INNER JOIN [pharmacy] 
	ON pharmacy.id_pharmacy = [order].id_pharmacy
INNER JOIN [production] 
	ON production.id_production = [order].id_production 
INNER JOIN [company] 
	ON company.id_company = production.id_company
INNER JOIN [medicine]
	ON medicine.id_medicine = production.id_medicine
	WHERE 
	    medicine.name = 'Кордерон'
		AND company.name = 'Аргус'	

/*Дать список лекарств компании “Фарма”, на которые не были сделаны заказы
до 25 января.*/
SELECT medicine.name FROM [medicine]
WHERE medicine.id_medicine NOT IN 
   (SELECT production.id_medicine FROM [production]
	INNER JOIN [order]
		ON production.id_production = [order].id_production
	INNER JOIN [company]
		ON company.id_company = production.id_company	
		WHERE 
		    company.name = 'Фарма'
			AND [order].date <= '2019-01-25')

/*Дать минимальный и максимальный баллы лекарств каждой фирмы, которая
оформила не менее 120 заказов*/
SELECT MIN(pharmacy.rating) AS [min], MAX(pharmacy.rating) AS [max], company.name FROM [pharmacy]
INNER JOIN [order] 
	ON pharmacy.id_pharmacy = [order].id_pharmacy
INNER JOIN [production] 
	ON production.id_production = [order].id_production 
INNER JOIN [company] 
	ON company.id_company = production.id_company
	GROUP BY company.name
	HAVING COUNT(*) >= 120	

/*Дать списки сделавших заказы аптек по всем дилерам компании “AstraZeneca”.
Если у дилера нет заказов, в названии аптеки проставить NULL.*/
SELECT company.name AS company_name, pharmacy.name AS pharmacy_name, dealer.name AS dealer_name FROM [company]  
INNER JOIN [dealer] 
	ON dealer.id_company = company.id_company
LEFT JOIN [order] 
	ON [order].id_dealer = dealer.id_dealer
LEFT JOIN [pharmacy]
	ON pharmacy.id_pharmacy = [order].id_pharmacy 
	WHERE company.name = 'AstraZeneca'

/* Уменьшить на 20% стоимость всех лекарств, если она превышает 3000, а
длительность лечения не более 7 дней.*/
SELECT medicine.name, production.price, medicine.cure_duration FROM [production]
INNER JOIN [medicine] 
	ON medicine.id_medicine = production.id_medicine
	WHERE production.price > 3000
		AND medicine.cure_duration <= 7
UPDATE [production]
SET production.price = 0.8 * production.price
WHERE production.id_production IN
   (SELECT production.id_production FROM [production]
	INNER JOIN [medicine] 
		ON medicine.id_medicine = production.id_medicine
		WHERE production.price > 3000
			AND medicine.cure_duration <= 7)

/* Добавить необходимые индексы*/
CREATE INDEX IX_production_id_company ON production  
(
	id_company
);

CREATE INDEX IX_production_id_medicine ON production 
(
	id_medicine
);

CREATE INDEX IX_production_price ON production 
(
	price
);

CREATE INDEX IX_order_id_production ON [order] 
(
	id_production
);

CREATE INDEX IX_order_id_dealer ON [order] 
(
	id_dealer
);

CREATE INDEX IX_order_id_pharmacy ON [order] 
(
	id_pharmacy
);

CREATE INDEX IX_order_date ON [order] 
(
	[date]
);

CREATE INDEX IX_medicine_cure_duration ON medicine 
(
	cure_duration
);

CREATE INDEX IX_dealer_id_company ON dealer
(
	id_company
);














/*Для самоконтроля*/
SELECT GETUTCDATE();
SELECT * FROM [company];
SELECT * FROM [dealer];
SELECT * FROM [medicine];
SELECT * FROM [order];
SELECT * FROM [pharmacy];
SELECT * FROM [production]; 
