#!/usr/bin/clisp

(defun fact_itv (n)
	(if (= n 0)
	1	
	(let ((f 1))
		(loop for i from 1 to n
		do (setf f (* f  i)))
		f
	)
))

(defun fact_rec (n)
	(if (= n 0)
	1 
	(* n (fact_rec(- n 1)))) )

(format t "recursive~%")

(loop for i from 0 to 10
	do (format t "~D! = ~D~%" i (fact_rec i)))

(format t "iterative~%")

(loop for i from 0 to 10
	do (format t "~D! = ~D~%" i (fact_itv i)))

