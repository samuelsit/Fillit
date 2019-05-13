
t_list	*ft_put_in_list(t_list **list, void *content)
{
	t_list *elem;

	if (!(elem = malloc(sizeof(*element))))
		return (NULL);
	elem->content = content;
	elem->content_size = sizeof(*elem);
	elem->next = *list;
	return (elem);
}

t_list	*ft_addlst_end()
{
	
}
