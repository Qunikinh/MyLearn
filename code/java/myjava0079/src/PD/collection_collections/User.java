package PD.collection_collections;

public class User {
    private String name;
    private long id;
    private String ped;

    public User() {
        super();
    }

    public User(String name, long id, String ped) {
        super();
        this.name = name;
        this.id = id;
        this.ped = ped;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getPed() {
        return ped;
    }

    public void setPed(String ped) {
        this.ped = ped;
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