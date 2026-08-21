# CS 255 Model Application Short Paper

Roderick L. Hughey  
Southern New Hampshire University  
CS 255: System Analysis and Design  
July 29, 2026

## Process Model Application

I would apply process modeling to DriverPass by mapping the work users complete and the decisions the system must make between the start and end of each activity. The first workflow would cover registration and package enrollment. It would show a customer entering contact information, selecting a package, and receiving access only to the services included in that package. A second workflow would cover appointment scheduling from the availability search through confirmation. The model would include checks for remaining package hours, instructor availability, vehicle availability, and schedule conflicts before the appointment is saved. These steps reflect the services and user responsibilities described in the DriverPass interview (Southern New Hampshire University, n.d.).

Process modeling would also clarify practice testing, lesson completion, report generation, and password recovery. For a practice test, the model would show the student opening the test, answering questions, submitting the attempt, receiving a score, and having the dashboard updated. For an on-the-road lesson, it would show the instructor reviewing the assignment, completing the lesson, entering comments, and updating the student record. Data-flow and activity views would help Liam and other nontechnical stakeholders confirm what information enters each process, what result should be produced, and where an error or delay could occur. The model would be especially useful for finding missing decisions, duplicate steps, and scheduling bottlenecks before development begins.

## Object Model Application

I would apply object modeling by identifying the main items the system must store and assigning each item a clear responsibility. Core objects would include UserAccount, Role, Customer, TrainingPackage, Appointment, Instructor, Vehicle, Lesson, OnlineCourse, PracticeTest, TestAttempt, Report, and AuditEntry. A Customer object would contain identifying and contact information and would be associated with a selected TrainingPackage. An Appointment would connect one customer, one instructor, one vehicle, and a defined time period. A TestAttempt would connect a student to a specific practice test and would store the start time, completion time, score, and status.

The relationships are important because DriverPass rules depend on connected data. A package controls how many training hours a customer may schedule and whether online content and practice tests are available. An appointment cannot be confirmed unless the related customer, instructor, vehicle, and time slot are all valid. Object modeling would make those associations, multiplicities, attributes, and operations visible before the database and business logic are built. Encapsulating package calculations, appointment validation, score calculation, and permission checks within the appropriate objects would also reduce duplicated logic and make later changes easier. For example, a future Payment object or Reminder service could be added without rewriting the entire scheduling structure.

## Process and Object Model Comparison

The main advantage of process modeling is that it explains behavior in an order that users can follow. DriverPass employees can review a scheduling flow and quickly tell whether it matches the way a customer calls, selects a lesson, receives an instructor and vehicle, and confirms the appointment. Process models are also useful for showing alternate paths, such as an unavailable vehicle, insufficient package hours, a failed login, or a canceled lesson. Their main weakness is that they do not fully describe the structure of the data. A process may show that an appointment is created without clearly defining how Customer, Package, Instructor, Vehicle, and Lesson records are related.

Object modeling has the opposite strength. It gives developers a clearer plan for classes, database entities, attributes, methods, and relationships. That makes it valuable for preventing duplicated data, assigning responsibilities, enforcing role-based access, and preparing the system for growth. Its weakness is that a class structure does not show timing or the sequence of user actions very well. Liam, the secretary, or an instructor may understand a workflow more quickly than a diagram showing associations and multiplicities among system objects.

DriverPass should use both approaches because neither model covers the entire design by itself. Process models should validate how students and employees complete registration, testing, scheduling, lessons, reporting, and account recovery. Object models should verify that the system has the data structure and reusable components needed to support those workflows. Used together, the models reduce the chance of building a system with a polished interface but broken business rules, or a technically organized database that does not match the way DriverPass actually operates.

## References

Southern New Hampshire University. (n.d.). *DriverPass interview transcript* [Course document].
