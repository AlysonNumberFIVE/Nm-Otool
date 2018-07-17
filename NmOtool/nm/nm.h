/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:34:40 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/17 14:57:42 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <sys/stat.h>
# include <mach-o/loader.h>
# include <mach-o/swap.h>
# include "libft/libft.h"

void						segments(unsigned char *content, size_t size);
int							endswith(char *str, char *end);
void						nm_so(unsigned char *content, size_t size,
					void (*symbols)(void *), char *filepath);
void						last_word(unsigned char *content, size_t size);
void						arc_nm(void *content, size_t size, char *filename);
size_t						find_start_position(unsigned char *content,
					size_t size);
int							extract_name_list(unsigned char *content,
					size_t size);
int							find_begin(unsigned char *content, size_t size);
int							grab_labels(unsigned char *content, size_t size);
int							end_of_functions(unsigned char *content);
void						*first_obj_name(unsigned char *content,
					size_t *size);
void						*find_start(unsigned char *content, size_t size);
void						loop_nm(unsigned char *content, size_t size);
unsigned char				*function_name(unsigned char *content, size_t size);
char						**arraydup(char **array);
char						*charpush(char *str, char c);
char						**arraypush(char **arr, char *str);
int							arraylen(char **arr);
void						special_letters(unsigned n_sect,
					unsigned int n_type);
int							arc_magic(unsigned char *content);
int							signature_check(unsigned char *content);
void						recursive_nm(unsigned char *content, size_t size,
					int i, char *filename);
void						which(unsigned int n_type, unsigned int n_sect,
							unsigned int n_value);
int							is_64_or_32(struct mach_header *head);
int							read_file(void **content, size_t *size,
							char *filename);
void						symbols(void *content);
void						print_address_values(unsigned long long hex,
					int flag);
void						nm_64(struct mach_header *header,
					void *content, size_t size);
void						nm_32(struct mach_header *header,
							void *content);
void						string_segment(void *content,
							struct symtab_command *tab);
void						which_is_it_again(int n_sect, int n_type);
struct symtab_command		*iterate_through_load_commands(struct
					load_command *comm, int command_num);
void						print_name(const char *name);
unsigned char				*function_name(unsigned char *content, size_t size);
unsigned char				*obj_name(unsigned char *content);
unsigned char				*reverse_to_next_frame(unsigned char *content);
unsigned char				*next_frame(unsigned char *content, size_t size);
unsigned char				*name_space(unsigned char *content, size_t size);
unsigned char				*print_labels(unsigned char *content, size_t size);
unsigned char				*print_names(unsigned char *content,
					char *filepath);
unsigned char				*print_obj_name(unsigned char *content,
					size_t size);
unsigned char				*find_first_label_seg(unsigned char *content,
					size_t size);

#endif
