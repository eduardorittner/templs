# Simple template file creator

My notetaking setup is pretty simple, and it requires some pretty basic templates,
however after a while it gets boring to write them manually, so that's what this
tool is for.
I'm also using this as a way to make my first cli tool, so I'm just having fun
with creating more options and flexibility than I'll probably need, but that's
fine, since I'm 100% sure it would've taken me 1/10 of the time if I'd just done
this in python.
It would be nice if I could create different templates, change the file directory
and all that, add a bit of customization, you know?

## Features

- Create a tag for today
    templ today

- Create a tag for tomorrow
    templ tomorrow

- Create tags for the current month
    templ month

- Create tags for the current year
    templ year

- Create a tag for a specific day in the current month
    templ -d [day]

- Create tags for a whole month in the current year
    templ -m [month]

- Create tags for a whole year
    templ -y [year]
