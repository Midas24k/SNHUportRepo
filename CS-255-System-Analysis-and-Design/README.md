# CS 255: System Analysis and Design

## DriverPass Project

DriverPass was the client for both projects in CS 255. The company wanted a web-based system that would help students prepare for their driving exams through online training, practice exams, and behind-the-wheel instruction. The system also needed to support account creation, training package selection, driving lesson scheduling, progress tracking, instructor notes, reporting, and administrative tools. One of the most important design concerns was making sure the scheduling process did not allow conflicts between students, instructors, vehicles, or appointment times.

## What I Did Well

I think I did particularly well turning the information from the DriverPass interview into requirements that could actually guide development. Instead of treating features such as scheduling as a simple calendar function, I broke the process down into the rules that DriverPass would need the system to enforce. The design checks package hours, instructor availability, vehicle availability, and time-slot conflicts before an appointment can be confirmed. I also carried the same requirements into the UML diagrams and technical requirements so the different parts of the design supported each other instead of feeling like separate assignments.

## What I Would Revise

If I could revise one part of the work, I would continue improving the readability and traceability of the UML diagrams, especially the use case and class diagrams. As more requirements were added, the diagrams naturally became more detailed and harder to read at a glance. I would improve them by keeping the highest-level business interactions on the main diagrams and moving supporting details into smaller diagrams when needed. I would also create a simple requirement-to-diagram traceability table earlier in the process so every major requirement could be checked against the design before the final review.

## Interpreting the User's Needs

I interpreted the user's needs by looking at both what DriverPass directly requested and how the business would actually operate. For example, DriverPass did not only need customers to schedule lessons. The system also had to account for the customer's remaining package hours, the instructor assigned to the lesson, the available vehicle, and the requested time. The secretary needed to be able to help customers manage appointments, instructors needed access to their schedules and lesson notes, management needed reports, and the IT officer needed controlled administrative access. Considering the user's needs is important because a system can be technically functional and still fail if it does not match the way the client works. The design should solve the client's actual problem, not just satisfy a list of features.

## My Approach to Designing Software

My approach is to start with the people who will use the system and the problem the system is supposed to solve. From there, I separate functional requirements from nonfunctional requirements, identify assumptions and limitations, and then model the system from more than one point of view. Use case diagrams help show who interacts with the system, activity and sequence diagrams help explain workflows and decisions, and class diagrams help define the data and relationships behind those workflows. In future projects, I would continue using those techniques along with requirement traceability, early prototypes, iterative stakeholder review, and measurable performance and security requirements. The biggest thing I took from this course is that good system design is not just about drawing diagrams. The diagrams, requirements, and technical decisions all need to tell the same story.

## Portfolio Artifacts

### Project One

- [Business Requirements Document](Project-One/CS255_Project_One_Business_Requirements.md)
- [Model Application Short Paper](Project-One/CS255_Project_One_Model_Application_Short_Paper.md)

### Project Two

- [System Design Document](Project-Two/CS255_Project_Two_System_Design.md)
- [Client Presentation Content and Speaker Notes](Project-Two/CS255_Project_Two_Client_Presentation.md)

## Module Eight Submission

For the Module Eight journal submission, the two main portfolio artifacts are the Project One Business Requirements Document and the Project Two System Design Document. This README contains the required reflection for the course portfolio.
