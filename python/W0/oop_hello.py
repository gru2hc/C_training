class employee:
    def __init__(self,name,dob):
        self.name = name
        self.dob = dob
        self.salary = 50

    def salary_review(self,review):
        self.salary = self.salary*(1+review*0.01)

emp1 = employee("Nguyen Van A", 15022019)
print(emp1.name,emp1.dob,emp1.salary)
emp1.salary_review(50)
print(emp1.name,emp1.dob,emp1.salary)