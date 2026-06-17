# Write your MySQL query statement below
select 
st.student_id, st.student_name, su.subject_name, sum( case when su.subject_name = e.subject_name then 1 else 0 end) as attended_exams
from Students st
left join Examinations e
on st.student_id = e.student_id
cross join Subjects su
group by st.student_id, st.student_name, su.subject_name
order by st.student_id, st.student_name
;