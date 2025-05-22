package PD.collection_collections;

public class Employee {
    private long id;
    private String name;
    private long salay;

    public Employee() {
        super();
    }

    public Employee(String name, long salay) {
        super();
        this.name = name;
        this.salay = salay;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getSalay() {
        return salay;
    }

    public void setSalay(long salay) {
        this.salay = salay;
    }

    @Override
    public int hashCode() {
        return (int) id;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (obj instanceof User) {
            User other = (User) obj;
            return this.id == other.getId();

        }
        return false;
    }

    @Override
    public String toString() {
        return "User [name=" + name + ", id=" + id + "]";
    }
}
