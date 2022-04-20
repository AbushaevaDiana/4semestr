USE [university]

--1. �������� ������� �����.
ALTER TABLE [student]
  ADD CONSTRAINT FK_student_group
  FOREIGN KEY (id_group) REFERENCES [group] (id_group)
ALTER TABLE [lesson]
  ADD CONSTRAINT FK_lesson_teacher
  FOREIGN KEY (id_teacher) REFERENCES [teacher] (id_teacher)
ALTER TABLE [lesson]
  ADD CONSTRAINT FK_lesson_group
  FOREIGN KEY (id_group) REFERENCES [group] (id_group)
ALTER TABLE [lesson]
  ADD CONSTRAINT FK_lesson_subject
  FOREIGN KEY (id_subject) REFERENCES [subject] (id_subject)
ALTER TABLE [mark]
  ADD CONSTRAINT FK_mark_student
  FOREIGN KEY (id_student) REFERENCES [student] (id_student)
ALTER TABLE [mark]
  ADD CONSTRAINT FK_mark_lesson
  FOREIGN KEY (id_lesson) REFERENCES [lesson] (id_lesson)

--2. ������ ������ ��������� �� ����������� ���� ��� ��������� ������� ��������. �������� ������ ������ � �������������� view.

-- �������� View
DROP VIEW IF EXISTS dbo.students_marks_informatica
GO  
-- �������� View.
CREATE VIEW students_marks_informatica AS
SELECT student.[name], mark.mark FROM mark
INNER JOIN lesson 
	ON mark.id_lesson = lesson.id_lesson
INNER JOIN [subject] 
	ON lesson.id_subject = [subject].id_subject 
INNER JOIN student 
	ON mark.id_student = student.id_student
    WHERE [subject].[name] = N'�����������'
GO
-- ���������� ������
SELECT * FROM students_marks_informatica

/*3. ���� ���������� � ��������� � ��������� ������� �������� � ��������
��������. ���������� ��������� ��������, �� ������� ������ �� ��������,
������� ������� � ������. �������� � ���� ���������, �� �����
������������� ������.*/
DROP PROCEDURE IF EXISTS students_dolgi_procedure;
GO

CREATE PROCEDURE students_dolgi_procedure 
@id_group INT
AS
BEGIN
	SELECT student.[name], [subject].[name]
	FROM [student]
		LEFT JOIN [lesson] ON lesson.id_group = student.id_group
		LEFT JOIN [subject] ON [subject].id_subject = lesson.id_subject
		LEFT JOIN [mark] ON mark.id_lesson = lesson.id_lesson AND mark.id_student = student.id_student
	WHERE student.id_group = @id_group
	GROUP BY student.[name], [subject].[name]
	HAVING MAX(mark.mark) IS NULL
	ORDER BY student.[name], [subject].[name];
END
GO

select * from student where name = '���������� ���� �����������'
select * from mark where id_student = 62 and id_lesson in (  select top(1) id_lesson from lesson where mark.id_lesson = lesson.id_lesson and id_subject = 8  )

select * from subject where name = N'��������'

EXECUTE students_dolgi_procedure 1;
EXECUTE students_dolgi_procedure 3;
EXECUTE students_dolgi_procedure 2;
EXECUTE students_dolgi_procedure 4;


/*4. ���� ������� ������ ��������� �� ������� �������� ��� ��� ���������, ��
������� ���������� �� ����� 35 ���������.*/

SELECT [subject].[name], AVG(mark.mark) FROM mark
INNER JOIN lesson 
	ON mark.id_lesson = lesson.id_lesson
INNER JOIN [subject] 
	ON lesson.id_subject = [subject].id_subject 
INNER JOIN student 
	ON mark.id_student = student.id_student
	GROUP BY [subject].[name]
	HAVING COUNT(distinct student.id_student) >= 35

/*5. ���� ������ ��������� ������������� �� �� ���� ���������� ��������� �
��������� ������, �������, ��������, ����. ��� ���������� ������ ���������
���������� NULL ���� ������.*/
SELECT [group].[name] AS group_name, student.[name] AS student_name,[subject].[name] AS subject_name, lesson.[date], mark.mark  FROM lesson
LEFT JOIN [subject] 
	ON lesson.id_subject = [subject].id_subject 
LEFT JOIN [group]
	ON lesson.id_group = [group].id_group 
LEFT JOIN student 
	ON [group].id_group = student.id_group
RIGHT JOIN mark 
	ON lesson.id_lesson = mark.id_lesson
	WHERE [group].[name]  = '��'

/*6. ���� ��������� ������������� ��, ���������� ������ ������� 5 �� ��������
�� �� 12.05, �������� ��� ������ �� 1 ����.*/
SELECT [group].[name] AS group_name, student.[name] AS student_name, [subject].[name] AS subject_name, lesson.[date], mark.mark  FROM lesson
INNER JOIN [subject] 
	ON lesson.id_subject = [subject].id_subject 
INNER JOIN [group]
	ON lesson.id_group = [group].id_group 
INNER JOIN student 
	ON [group].id_group = student.id_group
INNER JOIN mark 
	ON lesson.id_lesson = mark.id_lesson
	WHERE [group].[name]  = '��'
		AND [subject].[name] = '��'
		AND lesson.[date] < '2019-05-12'
		AND mark.mark < 5
UPDATE mark
SET mark.mark = mark.mark + 1
WHERE mark.id_mark IN
	(SELECT mark.id_mark  FROM lesson
	INNER JOIN [subject] 
		ON lesson.id_subject = [subject].id_subject 
	INNER JOIN [group]
		ON lesson.id_group = [group].id_group 
	INNER JOIN student 
		ON [group].id_group = student.id_group
	INNER JOIN mark 
		ON lesson.id_lesson = mark.id_lesson
		WHERE [group].[name]  = '��'
			AND [subject].[name] = '��'
			AND lesson.[date] < '2019-05-12'
			AND mark.mark < 5)

--7. �������� ����������� �������.
CREATE INDEX IX_group_id_group ON [group]
(
	id_group 
);
CREATE INDEX IX_lesson_id_lesson ON [lesson]
(
	id_lesson 
);
CREATE INDEX IX_lesson_id_subject ON [lesson]
(
	id_subject 
);
CREATE INDEX IX_lesson_id_group ON [lesson]
(
	id_group 
);
CREATE INDEX IX_mark_id_lesson ON [mark]
(
	id_lesson
);
CREATE INDEX IX_mark_id_student ON [mark]
(
	id_student 
);
CREATE INDEX IX_subject_id_subject ON [subject]
(
	id_subject
);
CREATE INDEX IX_student_id_student ON [student]
(
	id_student
);
CREATE INDEX IX_student_id_group ON [student]
(
	id_group
);







SELECT * FROM [group];
SELECT * FROM [lesson];
SELECT * FROM [mark];
SELECT * FROM [student];
SELECT * FROM [subject];
SELECT * FROM [teacher]; 